#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <pbr/tool/almost.h>

TEST_CASE( "AlmostEqual" )
{
    CHECK( pbr::AlmostEqual( 1.000001f, 1.0f ) );
}
