#include <catch2/catch.hpp>

#include <pbr/core/ray.h>

TEST_CASE( "testRayDefaultConstructor" )
{
    pbr::Ray ray;
    CHECK( ray.GetOrigin() == gm::Vec3f( 0, 0, 0 ) );
    CHECK( ray.GetDirection() == gm::Vec3f( 0, 0, 0 ) );
    CHECK( ray.GetTime() == 0 );
    CHECK( ray.GetMaxMagnitude() == std::numeric_limits< float >::max() );
    CHECK( ray.GetMedium() == nullptr );
}

TEST_CASE( "testRayParameterizedConstructor" )
{
    pbr::Ray ray( gm::Vec3f( 2, 2, 4 ), gm::Vec3f( 0.5, 0, 0.5 ), 0.5f, 1000.0f, nullptr );
    CHECK( ray.GetOrigin() == gm::Vec3f( 2, 2, 4 ) );
    CHECK( ray.GetDirection() == gm::Vec3f( 0.5, 0.0, 0.5 ) );
    CHECK( ray.GetTime() == 0.5f );
    CHECK( ray.GetMaxMagnitude() == 1000.0f );
    CHECK( ray.GetMedium() == nullptr );
}

TEST_CASE( "testRayComputePosition" )
{
    pbr::Ray ray( gm::Vec3f( 1, 1, 1 ), gm::Vec3f( 0, 0, 1.0f ) );
    CHECK( ray.ComputePosition( 5 ) == gm::Vec3f( 1, 1, 6 ) );
}
