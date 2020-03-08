#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <pbr/types/vec3f.h>

#include <pbr/functions/dotProduct.h>
#include <pbr/functions/crossProduct.h>

TEST_CASE( "dotProduct" )
{
    pbr::DtVec3f lhs( 1.0, 0.5, 2.0 );
    pbr::DtVec3f rhs( 2.0, 5.0, 2.5 );
    float res;
    pbr::FnDotProduct( lhs, rhs, res );
    CHECK( res == Approx( 9.5f ) );
}

TEST_CASE( "crossProduct" )
{
    pbr::DtVec3f lhs( 1.0, 0.5, 2.0 );
    pbr::DtVec3f rhs( 2.0, 5.0, 2.5 );
    pbr::DtVec3f res;
    pbr::FnCrossProduct( lhs, rhs, res );
    CHECK( res[0] == Approx( -8.75f ) );
    CHECK( res[1] == Approx( 1.5f ) );
    CHECK( res[2] == Approx( 4.0f ) );
}
