#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <pbr/tool/log.h>

#include <pbr/type/vec3f.h>

#include <pbr/function/rayPosition.h>

TEST_CASE( "rayPosition" )
{
    pbr::Vec3f origin( 1.0, 0.0, 2.0 );
    pbr::Vec3f direction( 0.0, 1.0, 0.0 );
    pbr::Vec3f rayPos;
    pbr::FnRayPosition( origin, direction, 2.0f, rayPos );
    CHECK( rayPos == pbr::Vec3f( 1.0, 2.0, 2.0 ) );
}

