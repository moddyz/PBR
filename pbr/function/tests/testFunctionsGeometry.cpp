#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <pbr/tool/log.h>

#include <pbr/type/vec3f.h>

#include <pbr/function/boundsIntersection.h>
#include <pbr/function/boundsOverlap.h>
#include <pbr/function/boundsUnion.h>
#include <pbr/function/pointInsideBounds.h>
#include <pbr/function/pointInsideBoundsExclusive.h>
#include <pbr/function/boundsExpand.h>
#include <pbr/function/rayPosition.h>
#include <pbr/function/boundsDiagonal.h>

TEST_CASE( "rayPosition" )
{
    pbr::Vec3f origin( 1.0, 0.0, 2.0 );
    pbr::Vec3f direction( 0.0, 1.0, 0.0 );
    pbr::Vec3f rayPos;
    pbr::FnRayPosition( origin, direction, 2.0f, rayPos );
    CHECK( rayPos == pbr::Vec3f( 1.0, 2.0, 2.0 ) );
}

TEST_CASE( "boundsUnion" )
{
    pbr::Bounds3f boundsA( pbr::Vec3f( 0.0, 0.0, 0.0 ), pbr::Vec3f( 1.0, 1.0, 1.0 ) );
    pbr::Bounds3f boundsB( pbr::Vec3f( -1.0, -5.0, 1.0 ), pbr::Vec3f( 5.0, 1.0, 5.0 ) );
    pbr::Bounds3f boundsUnion;
    pbr::FnBoundsUnion( boundsA, boundsB, boundsUnion );
    CHECK( boundsUnion.Min() == pbr::Vec3f( -1.0, -5.0, 0.0 ) );
    CHECK( boundsUnion.Max() == pbr::Vec3f( 5.0, 1.0, 5.0 ) );
}

TEST_CASE( "boundsIntersection" )
{
    pbr::Bounds3f boundsA( pbr::Vec3f( 0.0, 0.0, 0.0 ), pbr::Vec3f( 1.0, 1.0, 1.0 ) );
    pbr::Bounds3f boundsB( pbr::Vec3f( -1.0, -5.0, 1.0 ), pbr::Vec3f( 5.0, 1.0, 5.0 ) );
    pbr::Bounds3f boundsIntersection;
    pbr::FnBoundsIntersection( boundsA, boundsB, boundsIntersection );
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
    pbr::FnBoundsOverlap( boundsA, boundsB, boundsOverlap );
    CHECK( boundsOverlap );

    // Does not overlap.
    pbr::FnBoundsOverlap( boundsA, boundsC, boundsOverlap );
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
    pbr::FnPointInsideBounds( pointA, bounds, inside );
    CHECK( inside );

    // Point is not inside bounds.
    pbr::FnPointInsideBounds( pointB, bounds, inside );
    CHECK( !inside );

    // Point is on bounds boundary (OK!).
    pbr::FnPointInsideBounds( pointC, bounds, inside );
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
    pbr::FnPointInsideBoundsExclusive( pointA, bounds, inside );
    CHECK( inside );

    // Point is not inside bounds.
    pbr::FnPointInsideBoundsExclusive( pointB, bounds, inside );
    CHECK( !inside );

    // Point is on bounds boundary (Not OK!).
    pbr::FnPointInsideBoundsExclusive( pointC, bounds, inside );
    CHECK( !inside );
}

TEST_CASE( "boundsExpand" )
{
    pbr::Bounds3f bounds( pbr::Vec3f( 0.0, 0.0, 0.0 ), pbr::Vec3f( 1.0, 1.0, 1.0 ) );
    pbr::Bounds3f expandedBounds;
    pbr::FnBoundsExpand( bounds, 1.0f, expandedBounds );
    CHECK( expandedBounds.Min() == pbr::Vec3f( -1.0, -1.0, -1.0 ) );
    CHECK( expandedBounds.Max() == pbr::Vec3f( 2.0, 2.0, 2.0 ) );
}

TEST_CASE( "boundsDiagonal" )
{
    pbr::Bounds3f bounds( pbr::Vec3f( -1.0, -1.0, -1.0 ), pbr::Vec3f( 1.0, 1.0, 1.0 ) );
    pbr::Vec3f diagonal;
    pbr::FnBoundsDiagonal( bounds, diagonal );
    CHECK( diagonal == pbr::Vec3f( 2.0, 2.0, 2.0 ) );
}
