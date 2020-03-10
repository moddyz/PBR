#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <pbr/types/vec3f.h>

#include <pbr/functions/crossProduct.h>
#include <pbr/functions/dotProduct.h>
#include <pbr/functions/length.h>
#include <pbr/functions/lengthSquared.h>
#include <pbr/functions/normalise.h>

TEST_CASE( "dotProduct" )
{
    pbr::Vec3f lhs( 1.0, 0.5, 2.0 );
    pbr::Vec3f rhs( 2.0, 5.0, 2.5 );
    float        res;
    pbr::FnDotProduct( lhs, rhs, res );
    CHECK( res == Approx( 9.5f ) );
}

TEST_CASE( "crossProduct" )
{
    pbr::Vec3f lhs( 1.0, 0.5, 2.0 );
    pbr::Vec3f rhs( 2.0, 5.0, 2.5 );
    pbr::Vec3f res;
    pbr::FnCrossProduct( lhs, rhs, res );
    CHECK( res.X() == Approx( -8.75f ) );
    CHECK( res.Y() == Approx( 1.5f ) );
    CHECK( res.Z() == Approx( 4.0f ) );
}

TEST_CASE( "lengthSquared" )
{
    pbr::Vec3f vector( 1.0, 2.0, 3.0 );
    float        lengthSquared;
    pbr::FnLengthSquared( vector, lengthSquared );
    CHECK( lengthSquared == Approx( 14.0f ) );
}

TEST_CASE( "length" )
{
    pbr::Vec3f vector( 1.0, 2.0, 3.0 );
    float        length;
    pbr::FnLength( vector, length );
    CHECK( length == Approx( 3.741657387 ) );
}

TEST_CASE( "normalise" )
{
    pbr::Vec3f vector( 1.0, 2.0, 3.0 );
    pbr::Vec3f normalised;
    pbr::FnNormalise( vector, normalised );
    CHECK( normalised.X() == Approx( 0.267261242 ) );
    CHECK( normalised.Y() == Approx( 0.534522484 ) );
    CHECK( normalised.Z() == Approx( 0.801783726 ) );
}
