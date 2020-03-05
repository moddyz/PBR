#include <pbr/tools/assert.h>
#include <pbr/tools/profile.h>

#include <algorithm>
#include <atomic>
#include <mutex>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <sstream>

namespace
{
/// Compute the duration between \ref i_start and \ref i_stop.
timespec computeDuration( const timespec& i_start, const timespec& i_stop )
{
    timespec duration;
    if ( ( i_stop.tv_nsec - i_start.tv_nsec ) < 0 )
    {
        duration.tv_sec  = i_stop.tv_sec - i_start.tv_sec - 1;
        duration.tv_nsec = i_stop.tv_nsec - i_start.tv_nsec + 1e9;
    }
    else
    {
        duration.tv_sec  = i_stop.tv_sec - i_start.tv_sec;
        duration.tv_nsec = i_stop.tv_nsec - i_start.tv_nsec;
    }
    return duration;
}

} // namespace

namespace pbr
{

constexpr size_t c_profileRecordStringCapacity = 88;

/// A single profile record.
struct alignas( 128 ) ProfileRecord
{
    char     m_string[ c_profileRecordStringCapacity ];   // 88 bytes
    timespec m_start = {0, 0}; // 104 bytes
    timespec m_stop  = {0, 0}; // 120 bytes
    uint32_t m_line  = 0;      // 124 bytes
    uint32_t  m_stack = 0;     // 128 bytes

    void Print() const
    {
        timespec duration     = computeDuration( m_start, m_stop );
        size_t   microseconds = duration.tv_sec * 1e6 + duration.tv_nsec / 1e3;

        std::stringstream ss;
        for ( size_t i = 0; i < m_stack; ++i )
        {
            ss << " ";
        }
        ss << "\\_";

        printf( "%s string: '%s', line: %u, stack: %u, duration: %lu us\n",
                ss.str().c_str(),
                m_string,
                m_line,
                m_stack,
                microseconds );
    }
};

static_assert( sizeof( ProfileRecord ) == 128 );

/// Singleton store of profile records.
class ProfileRecordStore final
{
public:
    ProfileRecordStore( size_t i_recordCapacity )
    {
        m_records.resize( i_recordCapacity );
    }

    ~ProfileRecordStore() = default;

    /// Cannot copy.
    ProfileRecordStore( const ProfileRecordStore& ) = delete;
    ProfileRecordStore& operator=( const ProfileRecordStore& ) = delete;

    /// Check out the next record to author timing and metadata into.
    ProfileRecord* CheckOut()
    {
        int index = m_recordIndex.fetch_add( 1, std::memory_order_relaxed );
        if ( index >= m_records.size() )
        {
            m_recordsLoopAround = true;

            // We only want one thread to perform the reset of m_recordIndex back to 0.
            // Until this exchange succeeds, profiles will end up entering this clause.
            int expected = index + 1;
            m_recordIndex.compare_exchange_strong( expected, 0 );

            // Make sure we don't step out of bounds for all profiles which enter this clause.
            index = index % m_records.size();
        }

        return &m_records[ index ];
    }

    /// Return a reference to the records.
    const std::vector< ProfileRecord >& GetRecords() const
    {
        return m_records;
    }

    /// Get the size of the records.
    size_t GetRecordsSize() const
    {
        if ( m_recordsLoopAround.load() )
        {
            // If we have reached capacity at some point, then all records are valid.
            return m_records.size();
        }
        else
        {
            int index = m_recordIndex.load();
            // There is a chance that we reach capacity between the:
            // m_recordsLoopAround.load()
            // and
            // m_recordIndex.load()
            // So make sure we return a size value.
            return index < m_records.size() ? index : m_records.size();
        }
    }

private:
    /// Current record index.
    std::atomic_int m_recordIndex{0};

    /// Have each record been authored at least once?
    std::atomic_bool m_recordsLoopAround{false};

    /// Allocated records.
    std::vector< ProfileRecord > m_records;
};

/// Global singleton.
static ProfileRecordStore* g_profileRecordStore = nullptr;

/// Global mutex to guard setup and teardown of store.
static std::mutex g_profileRecordStoreMutex;

void SetupProfiling( size_t i_capacity )
{
    const std::lock_guard< std::mutex > lock( g_profileRecordStoreMutex );
    if ( g_profileRecordStore == nullptr )
    {
        g_profileRecordStore = new ProfileRecordStore( i_capacity );
    }
}

void TeardownProfiling()
{
    const std::lock_guard< std::mutex > lock( g_profileRecordStoreMutex );
    if ( g_profileRecordStore != nullptr )
    {
        PBR_ASSERT( g_profileRecordStore != nullptr );
        delete g_profileRecordStore;
        g_profileRecordStore = nullptr;
    }
}

void PrintProfiling()
{
    const std::lock_guard< std::mutex > lock( g_profileRecordStoreMutex );
    if ( g_profileRecordStore == nullptr )
    {
        PBR_ASSERT( false );
        return;
    }

    size_t                       recordsSize = g_profileRecordStore->GetRecordsSize();
    printf( "Got records size: %lu\n", recordsSize );
    std::vector< ProfileRecord > records     = g_profileRecordStore->GetRecords();
    std::sort( records.begin(), records.begin() + recordsSize, []( const ProfileRecord& a, const ProfileRecord& b ) {
        if ( a.m_start.tv_sec == b.m_start.tv_sec )
        {
            return a.m_start.tv_nsec < b.m_start.tv_nsec;
        }
        else
        {
            return a.m_start.tv_sec < b.m_start.tv_sec;
        }
    } );

    for ( size_t recordIndex = 0; recordIndex < recordsSize; ++recordIndex )
    {
        records[ recordIndex ].Print();
    }

}

Profile::Profile( const char* i_file, uint32_t i_line, const char* i_string )
{
    if ( g_profileRecordStore != nullptr )
    {
        m_profileRecord = g_profileRecordStore->CheckOut();
        strncpy( m_profileRecord->m_string, i_string, c_profileRecordStringCapacity );
    }
}

/// Thread-local global for tracking stack position of this profile.
static thread_local uint32_t c_profileStack = 0;

void Profile::Start()
{
    if ( m_profileRecord != nullptr )
    {
        m_profileRecord->m_stack = c_profileStack++;
        clock_gettime( CLOCK_MONOTONIC, &( m_profileRecord->m_start ) );
    }
}

void Profile::Stop()
{
    if ( m_profileRecord != nullptr )
    {
        clock_gettime( CLOCK_MONOTONIC, &( m_profileRecord->m_stop ) );
        c_profileStack--;
    }
}

ScopedProfile::ScopedProfile( const char* i_file, uint32_t i_line, const char* i_string )
    : Profile( i_file, i_line, i_string )
{
    Start();
}

ScopedProfile::~ScopedProfile()
{
    Stop();
}

} // namespace pbr
