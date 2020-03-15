#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <pbr/tool/log.h>

#include <pbr/type/vec3f.h>

#include <pbr/function/boundsIntersection.h>
#include <pbr/function/boundsUnion.h>
#include <pbr/function/rayPosition.h>

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

