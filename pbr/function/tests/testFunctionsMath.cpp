#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <pbr/tool/log.h>

#include <pbr/type/vec3f.h>

#include <pbr/function/abs.h>
#include <pbr/function/ceil.h>
#include <pbr/function/coordinateSystem.h>
#include <pbr/function/crossProduct.h>
#include <pbr/function/distance.h>
#include <pbr/function/distanceSquared.h>
#include <pbr/function/dotProduct.h>
#include <pbr/function/faceForward.h>
#include <pbr/function/floor.h>
#include <pbr/function/length.h>
#include <pbr/function/lengthSquared.h>
#include <pbr/function/lerp.h>
#include <pbr/function/max.h>
#include <pbr/function/min.h>
#include <pbr/function/normalise.h>

TEST_CASE( "dotProduct" )
{
    pbr::Vec3f lhs( 1.0, 0.5, 2.0 );
    pbr::Vec3f rhs( 2.0, 5.0, 2.5 );
    float      res;
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

TEST_CASE( "length" )
{
    pbr::Vec3f vector( 1.0, 2.0, 3.0 );
    float      length;
    pbr::FnLength( vector, length );
    CHECK( length == Approx( 3.741657387 ) );
}

TEST_CASE( "lengthSquared" )
{
    pbr::Vec3f vector( 1.0, 2.0, 3.0 );
    float      lengthSquared;
    pbr::FnLengthSquared( vector, lengthSquared );
    CHECK( lengthSquared == Approx( 14.0f ) );
}

TEST_CASE( "distance" )
{
    pbr::Vec3f vectorA( 1.0, 2.0, 3.0 );
    pbr::Vec3f vectorB( 25.0, 10.0, -5.0 );
    float      distance;
    pbr::FnDistance( vectorA, vectorB, distance );
    CHECK( distance == Approx( 26.532999f ) );
}

TEST_CASE( "distanceSquared" )
{
    pbr::Vec3f vectorA( 1.0, 2.0, 3.0 );
    pbr::Vec3f vectorB( 25.0, 10.0, -5.0 );
    float      distanceSquared;
    pbr::FnDistanceSquared( vectorA, vectorB, distanceSquared );
    CHECK( distanceSquared == Approx( 704 ) );
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

TEST_CASE( "coordinateSystem" )
{
    pbr::Vec3f vector( 1.0, 0.0, 0.0 );
    pbr::Vec3f vector2, vector3;
    pbr::FnCoordinateSystem( vector, vector2, vector3 );
    CHECK( vector2 == pbr::Vec3f( 0.0, 0.0, 1.0 ) );
    CHECK( vector3 == pbr::Vec3f( 0.0, -1.0, 0.0 ) );
}

TEST_CASE( "lerp" )
{
    pbr::Vec3f a( 1.0, 1.0, 1.0 );
    pbr::Vec3f b( 3.0, 3.0, 3.0 );
    pbr::Vec3f interpolated;
    pbr::FnLerp( 0.5, a, b, interpolated );
    CHECK( interpolated == pbr::Vec3f( 2.0, 2.0, 2.0 ) );
}

TEST_CASE( "min" )
{
    pbr::Vec3f a( 1.0, 2.0, 5.0 );
    pbr::Vec3f b( 2.0, 3.0, 0.0 );
    pbr::Vec3f min;
    pbr::FnMin( a, b, min );
    CHECK( min == pbr::Vec3f( 1.0, 2.0, 0.0 ) );
}

TEST_CASE( "max" )
{
    pbr::Vec3f a( 1.0, 2.0, 5.0 );
    pbr::Vec3f b( 2.0, 3.0, 0.0 );
    pbr::Vec3f max;
    pbr::FnMax( a, b, max );
    CHECK( max == pbr::Vec3f( 2.0, 3.0, 5.0 ) );
}

TEST_CASE( "floor" )
{
    pbr::Vec3f value( 2.9, 3.5, 0.7 );
    pbr::Vec3f floored;
    pbr::FnFloor( value, floored );
    CHECK( floored == pbr::Vec3f( 2.0, 3.0, 0.0 ) );
}

TEST_CASE( "ceil" )
{
    pbr::Vec3f value( 2.9, 3.5, 1.0 );
    pbr::Vec3f ceiled;
    pbr::FnCeil( value, ceiled );
    CHECK( ceiled == pbr::Vec3f( 3.0, 4.0, 1.0 ) );
}

TEST_CASE( "abs" )
{
    pbr::Vec3f value( -2.9, 3.5, -1.0 );
    pbr::Vec3f absoluteValue;
    pbr::FnAbs( value, absoluteValue );
    CHECK( absoluteValue == pbr::Vec3f( 2.9, 3.5, 1.0 ) );
}

TEST_CASE( "faceForward" )
{
    pbr::Vec3f normal( 1, 1, 1 );
    pbr::Vec3f positionHemisphere( 3, 4, 5 );
    pbr::Vec3f forward;
    pbr::FnFaceForward( normal, positionHemisphere, forward );
    CHECK( forward == pbr::Vec3f( 1, 1, 1 ) );

    pbr::Vec3f negativeHemisphere( -3, 4, -5 );
    pbr::FnFaceForward( normal, negativeHemisphere, forward );
    CHECK( forward == pbr::Vec3f( -1, -1, -1 ) );
}
