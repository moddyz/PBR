#pragma once

#include <stdio.h>

/// \briief Logging utilities

#define PBR_LOG_INFO( format, ... ) pbr::Log( pbr::LogLevel::Info, format, ## __VA_ARGS__ );
#define PBR_LOG_WARN( format, ... ) pbr::Log( pbr::LogLevel::Warn, format, ## __VA_ARGS__ );
#define PBR_LOG_ERROR( format, ... ) pbr::Log( pbr::LogLevel::Error, format, ## __VA_ARGS__ );

namespace pbr
{
/// Levels of logging.
enum class LogLevel : int
{
    Info = 0,
    Warn,
    Error,
};

/// Logging utility with variadic arguments.
void Log( LogLevel i_logLevel, const char* i_format, ... );

} // namespace pbr
