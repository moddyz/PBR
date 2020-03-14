#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <pbr/tool/log.h>

TEST_CASE( "Log", "Info" )
{
    PBR_LOG_INFO( "foo\n" );
    PBR_LOG_INFO( "foo %s\n", "bar" );
}
