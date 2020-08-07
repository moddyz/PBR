#pragma once

/// \file core/film.h
///
/// Film class.

#include <pbr/pbr.h>

#include <gm/types/vec2fRange.h>
#include <gm/types/vec2i.h>

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

    /// Parameterized construction.?
    ///
    /// \param i_resolution The full resolution of the image to render.
    Film( const gm::Vec2i& i_resolution );

    // --------------------------------------------------------------------- //
    /// \name Member access
    // --------------------------------------------------------------------- //

    const gm::Vec2i& GetFullResolution() const
    {
        return m_resolution;
    }

private:
    gm::Vec2i m_resolution;
};

PBR_NS_CLOSE
