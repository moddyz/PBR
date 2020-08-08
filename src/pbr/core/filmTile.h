#pragma once

/// \file core/film.h
///
/// FilmTile class.

#include <vector>

#include <pbr/pbr.h>
#include <pbr/utils/diagnostic.h>

#include <gm/functions/content.h>
#include <gm/types/vec2i.h>
#include <gm/types/vec3f.h>

PBR_NS_OPEN

/// \typedef FilmTilePixel
///
/// A unit of image data within a FilmTile.
using FilmTilePixel = gm::Vec3f;

/// \class FilmTile
///
/// A bounded rectangular region of pixels which is part of a parent Film.
///
/// Access to a given FilmTile is performed sequential, but multiple FilmTile(s)
/// may be processed concurrently.
class FilmTile
{
public:
    // --------------------------------------------------------------------- //
    /// \name Construction
    // --------------------------------------------------------------------- //

    /// Parameterized construction.
    ///
    /// \param i_bounds The bounds of the pixels owned by this tile, relative to the parent film.
    explicit FilmTile( const gm::Vec2iRange& i_bounds )
        : m_bounds( i_bounds )
    {
        GM_VERIFY( !m_bounds.IsEmpty() );
        m_buffer.resize( gm::Content( i_bounds ) );
    }

    // --------------------------------------------------------------------- //
    /// \name Bounding box
    // --------------------------------------------------------------------- //

    inline const gm::Vec2iRange& GetBounds() const
    {
        return m_bounds;
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
        int width  = m_bounds.Max().X() - m_bounds.Min().X();
        int offset = ( i_coord.X() - m_bounds.Min().X() ) + ( ( i_coord.Y() - m_bounds.Min().Y() ) * width );
        GM_ASSERT( offset < gm::Area( m_bounds ) );
        return m_buffer[ offset ];
    }

    /// Pixel write access.
    ///
    /// \param i_coord The 2D coordinate of the pixel to access.
    ///
    /// \return The pixel value.
    inline gm::Vec3f& GetPixel( const gm::Vec2i& i_coord )
    {
        int width  = m_bounds.Max().X() - m_bounds.Min().X();
        int offset = ( i_coord.X() - m_bounds.Min().X() ) + ( ( i_coord.Y() - m_bounds.Min().Y() ) * width );
        GM_ASSERT( offset < gm::Area( m_bounds ) );
        return m_buffer[ offset ];
    }

private:
    gm::Vec2iRange               m_bounds;
    std::vector< FilmTilePixel > m_buffer;
};

PBR_NS_CLOSE
