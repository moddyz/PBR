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
    gm::Mat4f matrix(
        1, 0, 0, 4,
        0, 1, 0, 5,
        0, 0, 1, 6,
        0, 0, 0, 1
    );
    pbr::Transform transform( matrix );
    CHECK( gm::MatrixProduct( transform.GetMatrix(), transform.GetInverseMatrix() )
           == gm::Mat4f::Identity() );
}

TEST_CASE( "testTransformInverse" )
{
    gm::Mat4f matrix(
        1, 0, 0, 4,
        0, 1, 0, 5,
        0, 0, 1, 6,
        0, 0, 0, 1
    );
    pbr::Transform transform( matrix );
    gm::Mat4f inverseMatrix = transform.GetInverseMatrix();

    pbr::Transform inverse = transform.Inverse();
    CHECK( inverse.GetMatrix() == inverseMatrix );
    CHECK( inverse.GetInverseMatrix() == matrix );
}

TEST_CASE( "testTransformTranspose" )
{
    gm::Mat4f matrix(
        1, 0, 0, 4,
        0, 1, 0, 5,
        0, 0, 1, 6,
        0, 0, 0, 1
    );
    pbr::Transform transform( matrix );

    pbr::Transform transpose = transform.Transpose();
    CHECK( transpose.GetMatrix() == gm::Mat4f(
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            4, 5, 6, 1
        )
    );
    CHECK( transpose.GetInverseMatrix() == gm::Mat4f(
             1,  0,  0, 0,
             0,  1,  0, 0,
             0,  0,  1, 0,
            -4, -5, -6, 1
        )
    );
}
