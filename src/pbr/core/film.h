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

/// \typedef FilmPixel
///
/// A unit of image data within a Film.
using FilmPixel = gm::Vec3f;

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
    /// \param i_cropWindow 2D values between (0,1) capturing a rectangular region
    /// within the full resolution to sample frm.
    Film( const gm::Vec2i& i_resolution );

    // --------------------------------------------------------------------- //
    /// \name Image bounds
    // --------------------------------------------------------------------- //

    inline const gm::Vec2i& GetFullResolution() const
    {
        return m_resolution;
    }

    /// Get the bounding region to sample from.
    inline gm::Vec2iRange GetSampleBounds() const
    {
        return m_sampleBounds;
    }

    // --------------------------------------------------------------------- //
    /// \name Tile access
    // --------------------------------------------------------------------- //

    /// Construct a new tile from this film.
    ///
    /// \param i_tileBounds The bounds of the requested tile.
    ///
    /// \return Newly constructed tile.
    std::unique_ptr< FilmTile > GetTile( const gm::Vec2iRange& i_tileBounds );

    /// Merge a tile and its sampled pixels back into this film.
    ///
    /// \param i_tile The tile to be merged.
    void MergeTile( std::unique_ptr< FilmTile > i_tile );

    // --------------------------------------------------------------------- //
    /// \name Pixel access
    // --------------------------------------------------------------------- //

    /// Get the pixel on this film by its coordinate.
    ///
    /// \param i_pixelCoord The pixel's 2D coordinate.
    ///
    /// \return The pixel value.
    FilmPixel& GetPixel( const gm::Vec2i& i_pixelCoord );

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
    gm::Vec2iRange m_sampleBounds;
    RGBImageBuffer m_buffer;
};

PBR_NS_CLOSE
