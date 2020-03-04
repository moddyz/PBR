#pragma once

#include <stdint.h>
#include <time.h>

/// \brief Performance profiling tools.
///
/// \usage
/// PBR_PROFILE_FUNCTION() will profile the execution time from when the macro was defined to when it is
/// no longer in scope.
///
/// PBR_PROFILE( "SomeString" ) is the same thing as PBR_PROFILE_FUNC, except it allows the developer to
/// specify an arbiturary string to publish in the record.

/* clang-format off */
#define _PBR_CONCAT(A, B) A B

#define _PBR_SCOPED_PROFILE( file, line, string ) \
    pbr::ScopedProfile profile##line( file, line, string );

#define PBR_PROFILE( string ) \
    _PBR_SCOPED_PROFILE( __FILE__, __LINE__, string )

#define PBR_PROFILE_FUNCTION() \
    _PBR_SCOPED_PROFILE( __FILE__, __LINE__, __PRETTY_FUNCTION__ )
/* clang-format on */

namespace pbr
{
/// Profile:
/// - records the timing on Start() and Stop().
/// - on Stop(), both timings are published.
class Profile
{
public:
    explicit Profile( const char* i_file, uint32_t i_line, const char* i_string );
    ~Profile() = default;

    // Cannot be copied.
    Profile( const Profile& i_profile ) = delete;
    Profile& operator=( const Profile& i_profile ) = delete;

    /// Record the starting time.
    void Start();

    /// Record the ending time.  Publish both the starting and ending time.
    void Stop();

    /// Print formatted timing information.
    void Print();

private:
    const char* m_file   = nullptr; // 8 bytes
    const char* m_string = nullptr; // 16 bytes
    timespec    m_start  = {0, 0};  // 32 bytes
    timespec    m_stop   = {0, 0};  // 48 bytes
    uint32_t    m_line   = 0;       // 52 bytes
    uint32_t    m_stack  = 0;       // 56 bytes
};

static_assert( sizeof( Profile ) == 56 );

/// Similar to the Profile, but does require explicit Start() and Stop() for timings.
/// Instead, the lifetime of a ScopedProfile object determines the timings.
/// The constructor and destructor will call Profile::Start() and Profile::Stop() respectively.
class ScopedProfile final : public Profile
{
public:
    explicit ScopedProfile( const char* i_file, uint32_t i_line, const char* i_string );
    ~ScopedProfile();

    // Cannot be copied.
    ScopedProfile( const ScopedProfile& i_profile ) = delete;
    ScopedProfile& operator=( const ScopedProfile& i_profile ) = delete;
};

void PrintProfile();

} // namespace pbr
