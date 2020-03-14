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

#define _PBR_SCOPED_PROFILE( file, line, string ) pbr::TlScopedProfile profile##line( file, line, string );
#define PBR_PROFILE( string ) _PBR_SCOPED_PROFILE( __FILE__, __LINE__, string )
#define PBR_PROFILE_FUNCTION() _PBR_SCOPED_PROFILE( __FILE__, __LINE__, __PRETTY_FUNCTION__ )

PBR_NAMESPACE_BEGIN

/// Fwd declaration.
class TlProfileRecord;

/// TlProfile records the timing on Start() and Stop().
/// It also includes metadata about the location in the source code and a user supplied string.
class TlProfile
{
public:
    explicit TlProfile( const char* i_file, uint32_t i_line, const char* i_string );
    ~TlProfile() = default;

    // Cannot be copied.
    TlProfile( const TlProfile& i_profile ) = delete;
    TlProfile& operator=( const TlProfile& i_profile ) = delete;

    /// Record the starting time.
    PBR_API
    void Start();

    /// Record the ending time.  Publish both the starting and ending time.
    PBR_API
    void Stop();

private:
    /// The profile record to author timings and metadata into.
    /// This memory is not owned by the TlProfile instance itself, but by the internal global record store.
    TlProfileRecord* m_profileRecord = nullptr;
};

/// Similar to the TlProfile, but does require explicit Start() and Stop() for timings.
/// Instead, the lifetime of a TlScopedProfile object determines the timings.
/// The constructor and destructor will call TlProfile::Start() and TlProfile::Stop() respectively.
class TlScopedProfile final : public TlProfile
{
public:
    explicit TlScopedProfile( const char* i_file, uint32_t i_line, const char* i_string );
    ~TlScopedProfile();

    // Cannot be copied.
    TlScopedProfile( const TlScopedProfile& i_profile ) = delete;
    TlScopedProfile& operator=( const TlScopedProfile& i_profile ) = delete;
};

/// Allocate memory used for profiling.
///
/// \param i_capacity total number of records to allocate.  If the number of profile instances exceed this number,
/// it will loop back to the initial record (oldest records will begin to be overwritten).
void TlProfileSetup( size_t i_capacity );

/// Deallocate memory used for profiling.
void TlProfileTeardown();

/// Print all profiled records.
void TlProfilePrint();

PBR_NAMESPACE_END
