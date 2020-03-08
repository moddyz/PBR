#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <pbr/functions/dotProduct.h>

TEST_CASE( "functions", "dotProduct" )
{
    pbr::Vec3Float lhs( 1.0, 0.5, 2.0 );
    pbr::Vec3Float rhs( 2.0, 5.0, 2.5 );
    float res;
    DotProduct( lhs, rhs, res );
    REQUIRE( res == Approx( 9.5f ) );
}
