#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <pbr/tool/log.h>

#include <pbr/function/abs.h>
#include <pbr/function/boundsDiagonal.h>
#include <pbr/function/boundsExpand.h>
#include <pbr/function/boundsIntersection.h>
#include <pbr/function/boundsMaxExtent.h>
#include <pbr/function/boundsOffset.h>
#include <pbr/function/boundsOverlap.h>
#include <pbr/function/boundsSurfaceArea.h>
#include <pbr/function/boundsUnion.h>
#include <pbr/function/boundsVolume.h>
#include <pbr/function/ceil.h>
#include <pbr/function/coordinateSystem.h>
#include <pbr/function/crossProduct.h>
#include <pbr/function/degreesToRadians.h>
#include <pbr/function/distance.h>
#include <pbr/function/distanceSquared.h>
#include <pbr/function/dotProduct.h>
#include <pbr/function/faceForward.h>
#include <pbr/function/floor.h>
#include <pbr/function/isIdentity.h>
#include <pbr/function/length.h>
#include <pbr/function/lengthSquared.h>
#include <pbr/function/lerp.h>
#include <pbr/function/lookAt.h>
#include <pbr/function/max.h>
#include <pbr/function/min.h>
#include <pbr/function/normalise.h>
#include <pbr/function/pointInsideBounds.h>
#include <pbr/function/pointInsideBoundsExclusive.h>
#include <pbr/function/radiansToDegrees.h>
#include <pbr/function/rayPosition.h>
#include <pbr/function/setIdentity.h>
#include <pbr/function/setRotate.h>
#include <pbr/function/setRotateX.h>
#include <pbr/function/setRotateY.h>
#include <pbr/function/setRotateZ.h>
#include <pbr/function/setScale.h>
#include <pbr/function/setTranslate.h>
#include <pbr/function/transformPoint.h>
#include <pbr/function/transformVector.h>
#include <pbr/function/transpose.h>

TEST_CASE( "dotProduct" )
{
    pbr::Vec3f lhs( 1.0, 0.5, 2.0 );
    pbr::Vec3f rhs( 2.0, 5.0, 2.5 );
    float      res;
    pbr::DotProduct( lhs, rhs, res );
    CHECK( res == Approx( 9.5f ) );
}

TEST_CASE( "crossProduct" )
{
    pbr::Vec3f lhs( 1.0, 0.5, 2.0 );
    pbr::Vec3f rhs( 2.0, 5.0, 2.5 );
    pbr::Vec3f res;
    pbr::CrossProduct( lhs, rhs, res );
    CHECK( res.X() == Approx( -8.75f ) );
    CHECK( res.Y() == Approx( 1.5f ) );
    CHECK( res.Z() == Approx( 4.0f ) );
}

TEST_CASE( "length" )
{
    pbr::Vec3f vector( 1.0, 2.0, 3.0 );
    float      length;
    pbr::Length( vector, length );
    CHECK( length == Approx( 3.741657387 ) );
}

TEST_CASE( "lengthSquared" )
{
    pbr::Vec3f vector( 1.0, 2.0, 3.0 );
    float      lengthSquared;
    pbr::LengthSquared( vector, lengthSquared );
    CHECK( lengthSquared == Approx( 14.0f ) );
}

TEST_CASE( "distance" )
{
    pbr::Vec3f vectorA( 1.0, 2.0, 3.0 );
    pbr::Vec3f vectorB( 25.0, 10.0, -5.0 );
    float      distance;
    pbr::Distance( vectorA, vectorB, distance );
    CHECK( distance == Approx( 26.532999f ) );
}

TEST_CASE( "distanceSquared" )
{
    pbr::Vec3f vectorA( 1.0, 2.0, 3.0 );
    pbr::Vec3f vectorB( 25.0, 10.0, -5.0 );
    float      distanceSquared;
    pbr::DistanceSquared( vectorA, vectorB, distanceSquared );
    CHECK( distanceSquared == Approx( 704 ) );
}

TEST_CASE( "normalise" )
{
    pbr::Vec3f vector( 1.0, 2.0, 3.0 );
    pbr::Vec3f normalised;
    pbr::Normalise( vector, normalised );
    CHECK( normalised.X() == Approx( 0.267261242 ) );
    CHECK( normalised.Y() == Approx( 0.534522484 ) );
    CHECK( normalised.Z() == Approx( 0.801783726 ) );
}

TEST_CASE( "coordinateSystem" )
{
    pbr::Vec3f vector( 1.0, 0.0, 0.0 );
    pbr::Vec3f vector2, vector3;
    pbr::CoordinateSystem( vector, vector2, vector3 );
    CHECK( vector2 == pbr::Vec3f( 0.0, 0.0, 1.0 ) );
    CHECK( vector3 == pbr::Vec3f( 0.0, -1.0, 0.0 ) );
}

TEST_CASE( "lerp" )
{
    pbr::Vec3f a( 1.0, 1.0, 1.0 );
    pbr::Vec3f b( 3.0, 3.0, 3.0 );
    pbr::Vec3f interpolated;
    pbr::Lerp( 0.5, a, b, interpolated );
    CHECK( interpolated == pbr::Vec3f( 2.0, 2.0, 2.0 ) );

    pbr::Vec3f    factor( 0.5, 0.25, 1.0 );
    pbr::Bounds3f bounds( pbr::Vec3f( 0.0, 0.0, 0.0 ), pbr::Vec3f( 1.0, 1.0, 1.0 ) );
    pbr::Lerp( factor, bounds, interpolated );
    CHECK( interpolated == pbr::Vec3f( 0.5, 0.25, 1.0 ) );
}

TEST_CASE( "lookAt" )
{
    pbr::Vec3f position( 2.0, 4.0, 3.0 );
    pbr::Vec3f lookAt( 2.0, 4.0, 5.0 );
    pbr::Vec3f up( 0.0, 1.0, 0.0 );

    pbr::Mat4f matrix;
    LookAt( position, lookAt, up, matrix );

    CHECK( matrix == pbr::Mat4f( 1.0, 0.0, 0.0, 2.0, 0.0, 1.0, 0.0, 4.0, 0.0, 0.0, 1.0, 3.0, 0.0, 0.0, 0.0, 1.0 ) );
}

TEST_CASE( "min" )
{
    pbr::Vec3f a( 1.0, 2.0, 5.0 );
    pbr::Vec3f b( 2.0, 3.0, 0.0 );
    pbr::Vec3f min;
    pbr::Min( a, b, min );
    CHECK( min == pbr::Vec3f( 1.0, 2.0, 0.0 ) );
}

TEST_CASE( "max" )
{
    pbr::Vec3f a( 1.0, 2.0, 5.0 );
    pbr::Vec3f b( 2.0, 3.0, 0.0 );
    pbr::Vec3f max;
    pbr::Max( a, b, max );
    CHECK( max == pbr::Vec3f( 2.0, 3.0, 5.0 ) );
}

TEST_CASE( "floor" )
{
    pbr::Vec3f value( 2.9, 3.5, 0.7 );
    pbr::Vec3f floored;
    pbr::Floor( value, floored );
    CHECK( floored == pbr::Vec3f( 2.0, 3.0, 0.0 ) );
}

TEST_CASE( "ceil" )
{
    pbr::Vec3f value( 2.9, 3.5, 1.0 );
    pbr::Vec3f ceiled;
    pbr::Ceil( value, ceiled );
    CHECK( ceiled == pbr::Vec3f( 3.0, 4.0, 1.0 ) );
}

TEST_CASE( "abs" )
{
    pbr::Vec3f value( -2.9, 3.5, -1.0 );
    pbr::Vec3f absoluteValue;
    pbr::Abs( value, absoluteValue );
    CHECK( absoluteValue == pbr::Vec3f( 2.9, 3.5, 1.0 ) );
}

TEST_CASE( "faceForward" )
{
    pbr::Vec3f normal( 1, 1, 1 );
    pbr::Normalise( normal, normal );
    pbr::Vec3f positionHemisphere( 3, 4, 5 );
    pbr::Vec3f forward;
    pbr::FaceForward( normal, positionHemisphere, forward );
    CHECK( forward == normal );

    pbr::Vec3f negativeHemisphere( -3, 4, -5 );
    pbr::FaceForward( normal, negativeHemisphere, forward );
    CHECK( forward == -normal );
}

TEST_CASE( "setIdentity" )
{
    pbr::Mat4f matrix;
    pbr::SetIdentity( matrix );
    CHECK( matrix == pbr::Mat4f( 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0 ) );
}

TEST_CASE( "isIdentity" )
{
    pbr::Mat4f matrixA( 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0 );
    pbr::Mat4f matrixB( 1.0, 0.0, 0.0, 0.0, 6.0, 7.0, 0.0, 0.0, 0.0, 0.0, 1.0, 7.0, -4.0, 5.0, 0.0, 1.0 );
    bool       isIdentity = false;

    pbr::IsIdentity( matrixA, isIdentity );
    CHECK( isIdentity );

    pbr::IsIdentity( matrixB, isIdentity );
    CHECK( !isIdentity );
}

TEST_CASE( "transpose" )
{
    pbr::Mat4f matrix( 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 2.0, 2.0, 3.0, 3.0, 3.0, 3.0, 4.0, 4.0, 4.0, 4.0 );
    pbr::Mat4f transposedMatrix;
    pbr::Transpose( matrix, transposedMatrix );
    CHECK( transposedMatrix ==
           pbr::Mat4f( 1.0, 2.0, 3.0, 4.0, 1.0, 2.0, 3.0, 4.0, 1.0, 2.0, 3.0, 4.0, 1.0, 2.0, 3.0, 4.0 ) );
}

TEST_CASE( "transformPoint" )
{
    // Construct transformation matrix.
    pbr::Mat4f matrix;
    pbr::SetIdentity( matrix );
    pbr::SetTranslate( pbr::Vec3f( 1.0f, 5.0f, 9.0f ), matrix );

    // Transform point.
    pbr::Vec3f point;
    pbr::TransformPoint( point, matrix, point );

    // Check.
    CHECK( point == pbr::Vec3f( 1.0f, 5.0f, 9.0f ) );
}

TEST_CASE( "transformVector" )
{
    // Construct transformation matrix.
    pbr::Mat4f matrix;
    pbr::SetIdentity( matrix );
    pbr::SetTranslate( pbr::Vec3f( 1.0f, 5.0f, 9.0f ), matrix );

    // Transform vector.
    pbr::Vec3f vector;
    pbr::TransformPoint( vector, matrix, vector );

    // Check.
    CHECK( vector == pbr::Vec3f( 1.0f, 5.0f, 9.0f ) );
}

TEST_CASE( "setTranslate" )
{
    pbr::Mat4f matrix( 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0 );
    pbr::Vec3f translate( 2.0, 3.0, 4.0 );
    pbr::SetTranslate( translate, matrix );
    CHECK( matrix == pbr::Mat4f( 1.0, 0.0, 0.0, 2.0, 0.0, 1.0, 0.0, 3.0, 0.0, 0.0, 1.0, 4.0, 0.0, 0.0, 0.0, 1.0 ) );
}

TEST_CASE( "setScale" )
{
    pbr::Mat4f matrix( 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0 );
    pbr::Vec3f scale( 2.0, 3.0, 4.0 );
    pbr::SetScale( scale, matrix );
    CHECK( matrix == pbr::Mat4f( 2.0, 0.0, 0.0, 0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0 ) );
}

TEST_CASE( "setRotateX" )
{
    pbr::Mat4f matrix( 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0 );
    float      degrees = 90.0f;
    pbr::SetRotateX( degrees, matrix );
    CHECK( matrix == pbr::Mat4f( 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 ) );
}

TEST_CASE( "setRotateY" )
{
    pbr::Mat4f matrix( 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0 );
    float      degrees = 90.0f;
    pbr::SetRotateY( degrees, matrix );
    CHECK( matrix == pbr::Mat4f( 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 ) );
}

TEST_CASE( "setRotateZ" )
{
    pbr::Mat4f matrix( 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0 );
    float      degrees = 90.0f;
    pbr::SetRotateZ( degrees, matrix );
    CHECK( matrix == pbr::Mat4f( 0.0, -1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0 ) );
}

TEST_CASE( "setRotate" )
{
    pbr::Mat4f matrix( 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0 );
    float      degrees = 90.0f;
    pbr::Vec3f axis( 0.0, 0.0, 1.0 );
    pbr::SetRotate( degrees, axis, matrix );
    CHECK( matrix == pbr::Mat4f( 0.0, -1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0 ) );
}

TEST_CASE( "rayPosition" )
{
    pbr::Vec3f origin( 1.0, 0.0, 2.0 );
    pbr::Vec3f direction( 0.0, 1.0, 0.0 );
    pbr::Vec3f rayPos;
    pbr::RayPosition( origin, direction, 2.0f, rayPos );
    CHECK( rayPos == pbr::Vec3f( 1.0, 2.0, 2.0 ) );
}

TEST_CASE( "boundsUnion" )
{
    pbr::Bounds3f boundsA( pbr::Vec3f( 0.0, 0.0, 0.0 ), pbr::Vec3f( 1.0, 1.0, 1.0 ) );
    pbr::Bounds3f boundsB( pbr::Vec3f( -1.0, -5.0, 1.0 ), pbr::Vec3f( 5.0, 1.0, 5.0 ) );
    pbr::Bounds3f boundsUnion;
    pbr::BoundsUnion( boundsA, boundsB, boundsUnion );
    CHECK( boundsUnion.Min() == pbr::Vec3f( -1.0, -5.0, 0.0 ) );
    CHECK( boundsUnion.Max() == pbr::Vec3f( 5.0, 1.0, 5.0 ) );
}

TEST_CASE( "boundsIntersection" )
{
    pbr::Bounds3f boundsA( pbr::Vec3f( 0.0, 0.0, 0.0 ), pbr::Vec3f( 1.0, 1.0, 1.0 ) );
    pbr::Bounds3f boundsB( pbr::Vec3f( -1.0, -5.0, 1.0 ), pbr::Vec3f( 5.0, 1.0, 5.0 ) );
    pbr::Bounds3f boundsIntersection;
    pbr::BoundsIntersection( boundsA, boundsB, boundsIntersection );
    CHECK( boundsIntersection.Min() == pbr::Vec3f( 0.0, 0.0, 1.0 ) );
    CHECK( boundsIntersection.Max() == pbr::Vec3f( 1.0, 1.0, 1.0 ) );
}

TEST_CASE( "boundsOverlap" )
{
    pbr::Bounds3f boundsA( pbr::Vec3f( 0.0, 0.0, 0.0 ), pbr::Vec3f( 1.0, 1.0, 1.0 ) );
    pbr::Bounds3f boundsB( pbr::Vec3f( -1.0, -5.0, 1.0 ), pbr::Vec3f( 5.0, 1.0, 5.0 ) );
    pbr::Bounds3f boundsC( pbr::Vec3f( -2.0, -2.0, -2.0 ), pbr::Vec3f( -1.0, -1.0, -1.0 ) );

    // Does overlap.
    bool boundsOverlap;
    pbr::BoundsOverlap( boundsA, boundsB, boundsOverlap );
    CHECK( boundsOverlap );

    // Does not overlap.
    pbr::BoundsOverlap( boundsA, boundsC, boundsOverlap );
    CHECK( !boundsOverlap );
}

TEST_CASE( "pointInsideBounds" )
{
    pbr::Bounds3f bounds( pbr::Vec3f( 0.0, 0.0, 0.0 ), pbr::Vec3f( 1.0, 1.0, 1.0 ) );
    pbr::Vec3f    pointA( 0.5, 0.5, 0.5 );
    pbr::Vec3f    pointB( 1.5, 1.5, 1.5 );
    pbr::Vec3f    pointC( 1.0, 1.0, 1.0 );

    // Point is inside bounds.
    bool inside;
    pbr::PointInsideBounds( pointA, bounds, inside );
    CHECK( inside );

    // Point is not inside bounds.
    pbr::PointInsideBounds( pointB, bounds, inside );
    CHECK( !inside );

    // Point is on bounds boundary (OK!).
    pbr::PointInsideBounds( pointC, bounds, inside );
    CHECK( inside );
}

TEST_CASE( "pointInsideBoundsExclusive" )
{
    pbr::Bounds3f bounds( pbr::Vec3f( 0.0, 0.0, 0.0 ), pbr::Vec3f( 1.0, 1.0, 1.0 ) );
    pbr::Vec3f    pointA( 0.5, 0.5, 0.5 );
    pbr::Vec3f    pointB( 1.5, 1.5, 1.5 );
    pbr::Vec3f    pointC( 1.0, 1.0, 1.0 );

    // Point is inside bounds.
    bool inside;
    pbr::PointInsideBoundsExclusive( pointA, bounds, inside );
    CHECK( inside );

    // Point is not inside bounds.
    pbr::PointInsideBoundsExclusive( pointB, bounds, inside );
    CHECK( !inside );

    // Point is on bounds boundary (Not OK!).
    pbr::PointInsideBoundsExclusive( pointC, bounds, inside );
    CHECK( !inside );
}

TEST_CASE( "boundsExpand" )
{
    pbr::Bounds3f bounds( pbr::Vec3f( 0.0, 0.0, 0.0 ), pbr::Vec3f( 1.0, 1.0, 1.0 ) );
    pbr::Bounds3f expandedBounds;
    pbr::BoundsExpand( bounds, 1.0f, expandedBounds );
    CHECK( expandedBounds.Min() == pbr::Vec3f( -1.0, -1.0, -1.0 ) );
    CHECK( expandedBounds.Max() == pbr::Vec3f( 2.0, 2.0, 2.0 ) );
}

TEST_CASE( "boundsDiagonal" )
{
    pbr::Bounds3f bounds( pbr::Vec3f( -1.0, -1.0, -1.0 ), pbr::Vec3f( 1.0, 1.0, 1.0 ) );
    pbr::Vec3f    diagonal;
    pbr::BoundsDiagonal( bounds, diagonal );
    CHECK( diagonal == pbr::Vec3f( 2.0, 2.0, 2.0 ) );
}

TEST_CASE( "boundsSurfaceArea" )
{
    pbr::Bounds3f bounds( pbr::Vec3f( -1.0, -1.0, -1.0 ), pbr::Vec3f( 1.0, 1.0, 1.0 ) );
    float         surfaceArea;
    pbr::BoundsSurfaceArea( bounds, surfaceArea );
    CHECK( surfaceArea == 12.0 );
}

TEST_CASE( "boundsVolume" )
{
    pbr::Bounds3f bounds( pbr::Vec3f( -1.0, -1.0, -1.0 ), pbr::Vec3f( 1.0, 1.0, 1.0 ) );
    float         volume;
    pbr::BoundsVolume( bounds, volume );
    CHECK( volume == 8.0 );
}

TEST_CASE( "boundsOffset" )
{
    pbr::Bounds3f bounds( pbr::Vec3f( -1.0, -1.0, -1.0 ), pbr::Vec3f( 1.0, 1.0, 1.0 ) );
    pbr::Vec3f    point( 0.0, 0.0, 0.0 );
    pbr::Vec3f    offset;
    pbr::BoundsOffset( bounds, point, offset );
    CHECK( offset == pbr::Vec3f( 0.5, 0.5, 0.5 ) );
}

TEST_CASE( "boundsMaxExtent" )
{
    pbr::Bounds3f bounds( pbr::Vec3f( 0.0, 0.0, 0.0 ), pbr::Vec3f( 1.0, 2.0, 3.0 ) );
    size_t        maxExtentIndex;
    pbr::BoundsMaxExtent( bounds, maxExtentIndex );
    CHECK( maxExtentIndex == 2 );
}

TEST_CASE( "radiansToDegrees" )
{
    float degrees = 90.0f;
    float radians;
    pbr::DegreesToRadians( degrees, radians );
    CHECK( radians == Approx( 1.5707963267948966 ) );
}

TEST_CASE( "degreesToRadians" )
{
    float radians = 1.5707963267948966f;
    float degrees;
    pbr::RadiansToDegrees( radians, degrees );
    CHECK( degrees == Approx( 90.0f ) );
}
