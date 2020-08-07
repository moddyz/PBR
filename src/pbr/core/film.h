#pragma once

/// \file core/film.h
///
/// Film class.

#include <vector>

#include <pbr/core/imageBuffer.h>
#include <pbr/pbr.h>

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
    /// \name Pixel access
    // --------------------------------------------------------------------- //

    /// Pixel read access.
    ///
    /// \param i_coord The 2D coordinate of the pixel to access.
    ///
    /// \return The pixel value.
    inline const gm::Vec3f& GetPixel( const gm::Vec2i& i_coord ) const
    {
        return m_buffer( i_coord.X(), i_coord.Y() );
    }

    /// Pixel write access.
    ///
    /// \param i_coord The 2D coordinate of the pixel to access.
    ///
    /// \return The pixel value.
    inline gm::Vec3f& GetPixel( const gm::Vec2i& i_coord )
    {
        return m_buffer( i_coord.X(), i_coord.Y() );
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
