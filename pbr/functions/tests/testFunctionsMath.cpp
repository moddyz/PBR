#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <pbr/functions/dotProduct.h>

TEST_CASE( "functions", "dotProduct" )
{
    pbr::DtVec3Float lhs( 1.0, 0.5, 2.0 );
    pbr::DtVec3Float rhs( 2.0, 5.0, 2.5 );
    float res;
    pbr::FnDotProduct( lhs, rhs, res );
    REQUIRE( res == Approx( 9.5f ) );
}

TEST_CASE( "functions", "crossProduct" )
{
    pbr::DtVec3Float lhs( 1.0, 0.5, 2.0 );
    pbr::DtVec3Float rhs( 2.0, 5.0, 2.5 );
    pbr::DtVec3Float res;
    pbr::FnCrossProduct( lhs, rhs, res );
    REQUIRE( res[0] == Approx( 9.5f ) );
    REQUIRE( res[1] == Approx( 9.5f ) );
    REQUIRE( res[2] == Approx( 9.5f ) );
}
