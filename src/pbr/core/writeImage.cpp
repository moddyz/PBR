#include <pbr/core/writeImage.h>

#include <gm/types/intRange.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

#include <vector>

PBR_NS_OPEN

bool WriteRGBImage( const RGBImageBuffer& i_imageBuffer, const std::string& i_filePath )
{
    size_t                 numChannels = RGBImageBuffer::ValueType::GetElementSize();
    std::vector< uint8_t > pixels( i_imageBuffer.Width() * i_imageBuffer.Height() * numChannels );

    for ( int yCoord = i_imageBuffer.Height() - 1; yCoord >= 0; yCoord-- )
    {
        for ( int xCoord : gm::IntRange( 0, i_imageBuffer.Width() ) )
        {
            const gm::Vec3f& pixel = i_imageBuffer( xCoord, yCoord );

            int pixelOffset           = ( yCoord * i_imageBuffer.Width() + xCoord ) * numChannels;
            pixels[ pixelOffset ]     = static_cast< uint8_t >( 255.999 * pixel[ 0 ] );
            pixels[ pixelOffset + 1 ] = static_cast< uint8_t >( 255.999 * pixel[ 1 ] );
            pixels[ pixelOffset + 2 ] = static_cast< uint8_t >( 255.999 * pixel[ 2 ] );
        }
    }

    return stbi_write_jpg( i_filePath.c_str(),
                           i_imageBuffer.Width(),
                           i_imageBuffer.Height(),
                           numChannels,
                           pixels.data(),
                           100 );
}

PBR_NS_CLOSE
