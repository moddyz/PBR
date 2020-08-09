#include <pbr/core/film.h>
#include <pbr/core/writeImage.h>

#include <gm/functions/ceil.h>

PBR_NS_OPEN

Film::Film( const gm::Vec2i& i_resolution )
    : m_resolution( i_resolution )
{
    m_sampleBounds = gm::Vec2iRange( gm::Vec2i( 0, 0 ), m_resolution );
    m_buffer.Resize( i_resolution.X(), i_resolution.Y() );
}

std::unique_ptr< FilmTile > Film::GetTile( const gm::Vec2iRange& i_tileBounds )
{
    return std::make_unique< FilmTile >( FilmTile( i_tileBounds ) );
}

void Film::MergeTile( std::unique_ptr< FilmTile > i_tile )
{
    for ( gm::Vec2i pixelCoord : i_tile->GetPixelBounds() )
    {
        const FilmTilePixel& tilePixel = i_tile->GetPixel( pixelCoord );
        FilmPixel&           filmPixel = GetPixel( pixelCoord );
        filmPixel                      = tilePixel;
    }
}

bool Film::WriteImage( const std::string& i_filePath ) const
{
    return WriteRGBImage( m_buffer, i_filePath );
}

PBR_NS_CLOSE
