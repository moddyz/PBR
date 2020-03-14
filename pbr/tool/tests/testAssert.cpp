#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <pbr/tool/assert.h>

TEST_CASE( "Assert", "Assert" )
{
    PBR_ASSERT( false );
    PBR_ASSERT_MSG( false, "Failure!!!!%s", "HAHA" );
}
