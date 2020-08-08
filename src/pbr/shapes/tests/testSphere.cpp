#include <catch2/catch.hpp>

#include <pbr/core/transform.h>
#include <pbr/shapes/sphere.h>

TEST_CASE( "testSphereParameterizedConstructor" )
{
    pbr::Transform transform = pbr::Transform::Translate( gm::Vec3f( 1, 2, 3 ) );
    pbr::Transform inverse   = transform.Inverse();
    pbr::Sphere    sphere( transform, inverse, 5 );
    CHECK( sphere.GetObjectToWorld() == transform );
    CHECK( sphere.GetWorldToObject() == inverse );
    CHECK( sphere.GetRadius() == 5 );
}

TEST_CASE( "testSphereComputeObjectBounds" )
{
    pbr::Transform transform = pbr::Transform::Translate( gm::Vec3f( 1, 1, 1 ) );
    pbr::Transform inverse   = transform.Inverse();
    pbr::Sphere    sphere( transform, inverse, 2 );
    CHECK( sphere.ComputeObjectBounds() == gm::Vec3fRange( gm::Vec3f( -2, -2, -2 ), gm::Vec3f( 2, 2, 2 ) ) );
}

TEST_CASE( "testSphereComputeWorldBounds" )
{
    pbr::Transform transform = pbr::Transform::Translate( gm::Vec3f( 1, 1, 1 ) );
    pbr::Transform inverse   = transform.Inverse();
    pbr::Sphere    sphere( transform, inverse, 2 );
    CHECK( sphere.ComputeWorldBounds() == gm::Vec3fRange( gm::Vec3f( -1, -1, -1 ), gm::Vec3f( 3, 3, 3 ) ) );
}
