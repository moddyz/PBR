#include <sstream>
#include <stdarg.h>
#include <stdio.h>

#include <pbr/tools/log.h>
#include <pbr/tools/assert.h>

namespace pbr
{
/// Logging utility with variadic arguments.
void Log( LogLevel i_logLevel, const char* i_message, ... )
{
    std::stringstream ss;
    switch ( i_logLevel )
    {
    case LogLevel::Info:
        ss << "[PBR INFO]";
        break;
    case LogLevel::Warn:
        ss << "[PBR WARN]";
        break;
    case LogLevel::Error:
        ss << "[PBR ERROR]";
        break;
    defaut:
        PBR_ASSERT_MSG( false, "Unknown log level %d", ( int ) i_logLevel );
        ss << "[Unknown]";
    }
    ss << " " << i_message << std::endl;

    std::string format = ss.str();
    va_list args;
    va_start( args, i_message );
    printf( ss.str().c_str(), args );
    va_end( args );
}

} // namespace pbr
