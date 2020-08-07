#include <pbr/core/film.h>
#include <pbr/core/writeImage.h>

PBR_NS_OPEN

Film::Film( const gm::Vec2i& i_resolution )
    : m_resolution( i_resolution )
    , m_buffer( i_resolution.X(), i_resolution.Y() )
{
}

bool Film::WriteImage( const std::string& i_filePath ) const
{
    return WriteRGBImage( m_buffer, i_filePath );
}

PBR_NS_CLOSE
