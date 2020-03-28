#pragma once

#include <stdint.h>
#include <time.h>

#include <pbr/api.h>

/// \brief Light-weight, thread-safe performance profiling tool.
///
/// SetupProfiling() will need to be explicitly called to allocate memory for storing profile records.
/// TeardownProfiling() can be called to de-allocate memory used to store profile records.
///
/// \usage
/// PBR_PROFILE_FUNCTION() will profile the execution time from when the macro was defined to when it is
/// no longer in scope.
///
/// PBR_PROFILE( "SomeString" ) is the same thing as PBR_PROFILE_FUNC, except it allows the developer to
/// specify an arbiturary string to publish in the record.

#define _PBR_SCOPED_PROFILE( file, line, string ) pbr::ScopedProfile profile##line( file, line, string );
#define PBR_PROFILE( string ) _PBR_SCOPED_PROFILE( __FILE__, __LINE__, string )
#define PBR_PROFILE_FUNCTION() _PBR_SCOPED_PROFILE( __FILE__, __LINE__, __PRETTY_FUNCTION__ )

PBR_NAMESPACE_BEGIN

/// Fwd declaration.
class ProfileRecord;

/// Profile records the timing on Start() and Stop().
/// It also includes metadata about the location in the source code and a user supplied string.
class Profile
{
public:
    explicit Profile( const char* i_file, uint32_t i_line, const char* i_string );
    ~Profile() = default;

    // Cannot be copied.
    Profile( const Profile& i_profile ) = delete;
    Profile& operator=( const Profile& i_profile ) = delete;

    /// Record the starting time.
    PBR_API
    void Start();

    /// Record the ending time.  Publish both the starting and ending time.
    PBR_API
    void Stop();

private:
    /// The profile record to author timings and metadata into.
    /// This memory is not owned by the Profile instance itself, but by the internal global record store.
    ProfileRecord* m_profileRecord = nullptr;
};

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

/// Allocate memory used for profiling.
///
/// \param i_capacity total number of records to allocate.  If the number of profile instances exceed this number,
/// it will loop back to the initial record (oldest records will begin to be overwritten).
void ProfileSetup( size_t i_capacity );

/// Deallocate memory used for profiling.
void ProfileTeardown();

/// Print all profiled records.
void ProfilePrint();

PBR_NAMESPACE_END
