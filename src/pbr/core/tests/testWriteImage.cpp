#include <catch2/catch.hpp>

#include <pbr/core/imageBuffer.h>
#include <pbr/core/writeImage.h>

TEST_CASE( "testWriteRGBImage" )
{
    pbr::RGBImageBuffer image( 640, 480 );
    for ( gm::Vec2i coord : image.Extent() )
    {
        float radiance = ( float ) coord.Y() / ( float ) image.Extent().Max().Y();
        image( coord.X(), coord.Y() ) = gm::Vec3f( radiance, radiance, radiance );
    }
    CHECK( WriteRGBImage( image, "/tmp/output.jpg" ) );
}
