#pragma once

/// \file core/cameraSample.h
///
/// CameraSample class.

#include <pbr/core/transform.h>

#include <gm/types/floatRange.h>

PBR_NS_OPEN

/// \class CameraSample
///
/// Specification of a ray generated from a camera.
class CameraSample
{
public:
    // --------------------------------------------------------------------- //
    /// \name Construction
    // --------------------------------------------------------------------- //

    /// Parameterized constructor.
    CameraSample( const gm::Vec2f& i_filmCoord, const gm::Vec2f& i_lensCoord, float i_time )
        : m_filmCoord( i_filmCoord )
        , m_lensCoord( i_lensCoord )
        , m_time( i_time )
    {
    }

    // --------------------------------------------------------------------- //
    /// \name Member access
    // --------------------------------------------------------------------- //

    /// \return The coordinate on the film which the ray passes through.
    inline const gm::Vec2f& GetFilmCoord() const
    {
        return m_filmCoord;
    }

    /// \return The coordinate on the lens which the ray passes through.
    inline const gm::Vec2f& GetLensCoord() const
    {
        return m_lensCoord;
    }

    /// \return The time at which the ray should sample the scene.
    inline const gm::Vec2f& GetTime() const
    {
        return m_time;
    }

private:
    gm::Vec2f m_filmCoord;
    gm::Vec2f m_lensCoord;
    float     m_time = 0.0f;
};

PBR_NS_CLOSE
