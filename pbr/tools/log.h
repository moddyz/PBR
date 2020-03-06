#pragma once

#include <stdio.h>

/// \briief Logging utilities

#define PBR_LOG_INFO( format, ... ) printf( format, ## __VA_ARGS__ );
#define PBR_LOG_WARN( format, ... ) printf( format, ## __VA_ARGS__ );
#define PBR_LOG_ERROR( format, ... ) printf( format, ## __VA_ARGS__ );
