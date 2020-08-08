#pragma once

/// \file core/film.h
///
/// Film class.

#include <memory>
#include <vector>

#include <pbr/core/filmTile.h>
#include <pbr/core/imageBuffer.h>

#include <gm/types/vec2fRange.h>
#include <gm/types/vec2i.h>
#include <gm/types/vec3f.h>

PBR_NS_OPEN

/// \class Film
///
/// Record of image pixels produced from radiance collected through light samples.
class Film
{
public:
    // --------------------------------------------------------------------- //
    /// \name Construction
    // --------------------------------------------------------------------- //

    /// Parameterized construction.
    ///
    /// \param i_resolution The full resolution of the image to render.
    Film( const gm::Vec2i& i_resolution );

    // --------------------------------------------------------------------- //
    /// \name Member access
    // --------------------------------------------------------------------- //

    inline const gm::Vec2i& GetFullResolution() const
    {
        return m_resolution;
    }

    // --------------------------------------------------------------------- //
    /// \name Tile access
    // --------------------------------------------------------------------- //

    std::unique_ptr< FilmTile > GetTile( const gm::Vec2iRange& i_tileBounds )
    {
        return std::make_unique< FilmTile >( FilmTile( i_tileBounds ) );
    }

    // --------------------------------------------------------------------- //
    /// \name Serialization
    // --------------------------------------------------------------------- //

    /// Write the image recorded on this film out to disk.
    ///
    /// \param i_filePath The file path to write the image to.
    ///
    /// \return Whether or not the file was written successfully.
    bool WriteImage( const std::string& i_filePath ) const;

private:
    gm::Vec2i      m_resolution;
    RGBImageBuffer m_buffer;
};

PBR_NS_CLOSE
