#include <pbr/tools/profile.h>

#include <stdio.h>

namespace
{
/// Thread-local global for tracking profile stack .
static thread_local uint32_t c_profileStack = 0;

timespec computeDuration( const timespec& i_start, const timespec& i_stop )
{
    timespec duration;
    if ( ( i_stop.tv_nsec - i_start.tv_nsec ) < 0 )
    {
        duration.tv_sec  = i_stop.tv_sec - i_start.tv_sec - 1;
        duration.tv_nsec = i_stop.tv_nsec - i_start.tv_nsec + 1000000000;
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
Profile::Profile( const char* i_file, uint32_t i_line, const char* i_string )
    : m_file( i_file )
    , m_string( i_string )
    , m_line( i_line )
{
}

void Profile::Start()
{
    m_stack = c_profileStack++;
    clock_gettime( CLOCK_MONOTONIC, &m_start );
}

void Profile::Stop()
{
    clock_gettime( CLOCK_MONOTONIC, &m_stop );
    c_profileStack--;
    Print();
}

void Profile::Print()
{
    timespec duration = computeDuration( m_start, m_stop );
    size_t   microseconds = duration.tv_sec * 1e6 + duration.tv_nsec / 1e3;
    printf( "[Pbr Profile] file: %s: %u, %s, stack: %u, duration: %lu us\n",
            m_file,
            m_line,
            m_string,
            m_stack,
            microseconds );
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
