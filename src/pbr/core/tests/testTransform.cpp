#include <catch2/catch.hpp>

#include <pbr/core/transform.h>

TEST_CASE( "testTransformDefaultConstructor" )
{
    pbr::Transform transform;
    CHECK( transform.GetMatrix() == gm::Mat4f::Identity() );
    CHECK( transform.GetInverseMatrix() == gm::Mat4f::Identity() );
}

TEST_CASE( "testTransformSingleMatrixConstructor" )
{
    gm::Mat4f      matrix( 1, 0, 0, 4, 0, 1, 0, 5, 0, 0, 1, 6, 0, 0, 0, 1 );
    pbr::Transform transform( matrix );
    CHECK( gm::MatrixProduct( transform.GetMatrix(), transform.GetInverseMatrix() ) == gm::Mat4f::Identity() );
}

TEST_CASE( "testTransformInverse" )
{
    gm::Mat4f      matrix( 1, 0, 0, 4, 0, 1, 0, 5, 0, 0, 1, 6, 0, 0, 0, 1 );
    pbr::Transform transform( matrix );
    gm::Mat4f      inverseMatrix = transform.GetInverseMatrix();

    pbr::Transform inverse = transform.Inverse();
    CHECK( inverse.GetMatrix() == inverseMatrix );
    CHECK( inverse.GetInverseMatrix() == matrix );
}

TEST_CASE( "testTransformTranspose" )
{
    gm::Mat4f      matrix( 1, 0, 0, 4, 0, 1, 0, 5, 0, 0, 1, 6, 0, 0, 0, 1 );
    pbr::Transform transform( matrix );

    pbr::Transform transpose = transform.Transpose();
    CHECK( transpose.GetMatrix() == gm::Mat4f( 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 4, 5, 6, 1 ) );
    CHECK( transpose.GetInverseMatrix() == gm::Mat4f( 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, -4, -5, -6, 1 ) );
}

TEST_CASE( "testTransformIsIdentity" )
{
    CHECK( pbr::Transform().IsIdentity() );
    CHECK( !pbr::Transform::Translate( gm::Vec3f( 1, 2, 3 ) ).IsIdentity() );
}

TEST_CASE( "testTransformComposition" )
{
    pbr::Transform transformA( gm::Mat4f( 1, 0, 0, 1, 0, 1, 0, 2, 0, 0, 1, 3, 0, 0, 0, 1 ) );

    pbr::Transform transformB( gm::Mat4f( 1, 0, 0, 3, 0, 1, 0, 4, 0, 0, 1, 5, 0, 0, 0, 1 ) );

    pbr::Transform result = transformA * transformB;
    CHECK( result.GetMatrix() == gm::Mat4f( 1, 0, 0, 4, 0, 1, 0, 6, 0, 0, 1, 8, 0, 0, 0, 1 ) );
    CHECK( result.GetInverseMatrix() == gm::Mat4f( 1, 0, 0, -4, 0, 1, 0, -6, 0, 0, 1, -8, 0, 0, 0, 1 ) );
}

TEST_CASE( "testTransformEquality" )
{
    CHECK( pbr::Transform() == pbr::Transform() );
    CHECK( pbr::Transform::Translate( gm::Vec3f( 1, 2, 3 ) ) == pbr::Transform::Translate( gm::Vec3f( 1, 2, 3 ) ) );
    CHECK( pbr::Transform::Translate( gm::Vec3f( 1, 2, 3 ) ) != pbr::Transform::Translate( gm::Vec3f( 2, 3, 3 ) ) );
}

TEST_CASE( "testTransformTranslate" )
{
    pbr::Transform transform = pbr::Transform::Translate( gm::Vec3f( 1, 2, 3 ) );
    CHECK( transform.GetMatrix() == gm::Mat4f( 1, 0, 0, 1, 0, 1, 0, 2, 0, 0, 1, 3, 0, 0, 0, 1 ) );
    CHECK( transform.GetInverseMatrix() == gm::Mat4f( 1, 0, 0, -1, 0, 1, 0, -2, 0, 0, 1, -3, 0, 0, 0, 1 ) );
}

TEST_CASE( "testTransformScale" )
{
    pbr::Transform transform = pbr::Transform::Scale( gm::Vec3f( 1, 2, 4 ) );
    CHECK( transform.GetMatrix() == gm::Mat4f( 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 4, 0, 0, 0, 0, 1 ) );
    CHECK( transform.GetInverseMatrix() == gm::Mat4f( 1, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 0.25, 0, 0, 0, 0, 1 ) );
}

TEST_CASE( "testTransformRotateX" )
{
    pbr::Transform transform = pbr::Transform::RotateX( 45 );
    CHECK( transform.GetMatrix() ==
           gm::Mat4f( 1, 0, 0, 0, 0, 0.707107, -0.707107, 0, 0, 0.707107, 0.707107, 0, 0, 0, 0, 1 ) );
    CHECK( transform.GetInverseMatrix() ==
           gm::Mat4f( 1, 0, 0, 0, 0, 0.707107, 0.707107, 0, 0, -0.707107, 0.707107, 0, 0, 0, 0, 1 ) );
}

TEST_CASE( "testTransformRotateY" )
{
    pbr::Transform transform = pbr::Transform::RotateY( 45 );
    CHECK( transform.GetMatrix() ==
           gm::Mat4f( 0.707107, 0, 0.707107, 0, 0, 1, 0, 0, -0.707107, 0, 0.707107, 0, 0, 0, 0, 1 ) );
    CHECK( transform.GetInverseMatrix() ==
           gm::Mat4f( 0.707107, 0, -0.707107, 0, 0, 1, 0, 0, 0.707107, 0, 0.707107, 0, 0, 0, 0, 1 ) );
}

TEST_CASE( "testTransformRotateZ" )
{
    pbr::Transform transform = pbr::Transform::RotateZ( 45 );
    CHECK( transform.GetMatrix() ==
           gm::Mat4f( 0.707107, -0.707107, 0, 0, 0.707107, 0.707107, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 ) );
    CHECK( transform.GetInverseMatrix() ==
           gm::Mat4f( 0.707107, 0.707107, 0, 0, -0.707107, 0.707107, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 ) );
}

TEST_CASE( "testTransformRotate" )
{
    pbr::Transform transform = pbr::Transform::Rotate( 45, gm::Vec3f( 0, 0, 1 ) );
    CHECK( transform.GetMatrix() ==
           gm::Mat4f( 0.707107, -0.707107, 0, 0, 0.707107, 0.707107, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 ) );
    CHECK( transform.GetInverseMatrix() ==
           gm::Mat4f( 0.707107, 0.707107, 0, 0, -0.707107, 0.707107, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 ) );
}

TEST_CASE( "testTransformHasScale" )
{
    CHECK( !pbr::Transform::RotateX( 45 ).HasScale() );
    CHECK( !pbr::Transform::Translate( gm::Vec3f( 1, 2, 3 ) ).HasScale() );
    CHECK( pbr::Transform::Scale( gm::Vec3f( 1, 2, 3 ) ).HasScale() );
}

TEST_CASE( "testTransformVector" )
{
    gm::Vec3f vector( 0, 1, 0 );

    {
        pbr::Transform transform = pbr::Transform::Translate( gm::Vec3f( 1, 2, 3 ) );
        CHECK( transform.TransformVector( vector ) == vector );
    }

    {
        pbr::Transform transform = pbr::Transform::Scale( gm::Vec3f( 1, 2, 3 ) );
        CHECK( transform.TransformVector( vector ) == gm::Vec3f( 0, 2, 0 ) );
    }

    {
        pbr::Transform transform = pbr::Transform::RotateX( 45 );
        CHECK( transform.TransformVector( vector ) == gm::Vec3f( 0, 0.707107, 0.707107 ) );
    }
}

TEST_CASE( "testTransformPoint" )
{
    gm::Vec3f point( 0, 1, 0 );

    {
        pbr::Transform transform = pbr::Transform::Translate( gm::Vec3f( 1, 2, 3 ) );
        CHECK( transform.TransformPoint( point ) == gm::Vec3f( 1, 3, 3 ) );
    }

    {
        pbr::Transform transform = pbr::Transform::Scale( gm::Vec3f( 1, 2, 3 ) );
        CHECK( transform.TransformPoint( point ) == gm::Vec3f( 0, 2, 0 ) );
    }

    {
        pbr::Transform transform = pbr::Transform::RotateX( 45 );
        CHECK( transform.TransformPoint( point ) == gm::Vec3f( 0, 0.707107, 0.707107 ) );
    }
}

TEST_CASE( "testTransformBounds" )
{
    gm::Vec3fRange bounds( gm::Vec3f( -0.5, -0.5, -0.5 ), gm::Vec3f( 0.5, 0.5, 0.5 ) );

    {
        pbr::Transform transform = pbr::Transform::Translate( gm::Vec3f( 1, 2, 3 ) );
        CHECK( transform.TransformBounds( bounds ) ==
               gm::Vec3fRange( gm::Vec3f( 0.5, 1.5, 2.5 ), gm::Vec3f( 1.5, 2.5, 3.5 ) ) );
    }

    {
        pbr::Transform transform = pbr::Transform::Scale( gm::Vec3f( 1, 2, 3 ) );
        CHECK( transform.TransformBounds( bounds ) ==
               gm::Vec3fRange( gm::Vec3f( -0.5, -1, -1.5 ), gm::Vec3f( 0.5, 1, 1.5 ) ) );
    }

    {
        pbr::Transform transform = pbr::Transform::RotateX( 45 );
        CHECK( transform.TransformBounds( bounds ) ==
               gm::Vec3fRange( gm::Vec3f( -0.5, -0.707107, -0.707107 ), gm::Vec3f( 0.5, 0.707107, 0.707107 ) ) );
    }
}

