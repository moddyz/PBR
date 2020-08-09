#include <pbr/core/samplerIntegrator.h>
#include <pbr/core/film.h>

#include <gm/functions/min.h>

PBR_NS_OPEN

SamplerIntegrator::SamplerIntegrator( const CameraSharedPtr& i_camera, const SamplerSharedPtr& i_sampler )
    : m_camera( i_camera )
    , m_sampler( i_sampler )
{
}

void SamplerIntegrator::Render( const Scene& i_scene )
{
    // Get image bounds.
    gm::Vec2iRange sampleBounds = m_camera->GetFilm().GetSampleBounds();
    gm::Vec2i      sampleExtent = sampleBounds.Max() - sampleBounds.Min();

    // Subdivide image bounds into square tiles.
    const int tileSize = 16;
    gm::Vec2i tileDim( sampleExtent.X() + tileSize - 1 / tileSize, sampleExtent.Y() + tileSize - 1 / tileSize );

    // Loop over each tile.
    for ( gm::Vec2i tile : gm::Vec2iRange( gm::Vec2i(), tileDim ) )
    {
        // Global, unique tile index.
        int tileIndex = tile.Y() * tileDim.X() + tile.X();

        // Compute the pixels to loop over.
        gm::Vec2i tileMin( sampleBounds.Min().X() + tile.X() * tileSize, sampleBounds.Min().Y() + tile.Y() * tileSize );
        gm::Vec2i tileMax( tileMin.X() + tileSize, tileMin.Y() + tileSize );
        gm::Vec2iRange tileBounds( tileMin, gm::Min( tileMax, sampleBounds.Max() ) );

        // Construct tile, and loop over its pixels.
        std::unique_ptr< FilmTile > filmTile = m_camera->GetFilm().GetTile( tileBounds );
        for ( gm::Vec2i pixel : tileBounds )
        {
            // Collect light samples


        }

        // Merge sampled pixel values back into the tile.
        m_camera->GetFilm().MergeTile( std::move( filmTile ) );
    }
}

PBR_NS_CLOSE
