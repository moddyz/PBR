#pragma once

/// \file core/ray.h
///
/// Ray model for physically based rendering.

#include <pbr/pbr.h>

#include <sstream>

#include <gm/functions/rayPosition.h>
#include <gm/types/vec3f.h>

PBR_NS_OPEN

// Forward declarations
class Medium;

/// \class Ray
///
/// Model of a ray for rendering purposes.
///
/// The geometric components of a ray are its \em origin and \em direction.
///
/// A ray is associated with \em time.  This enables effects such as motion blur
/// by querying primitive attributes over multiple time samples.
///
/// A ray has an <em>maximum magnitude</em> to limit the extent of its validity, such as
/// preventing the ray from intersecting farther objects when its already intersected a closer one.
///
/// Finally, the ray is associated with a \ref Medium containing its origin.
class Ray final
{
public:
    // --------------------------------------------------------------------- //
    /// \name Construction
    // --------------------------------------------------------------------- //

    /// Default constructor.
    constexpr inline Ray() = default;

    /// Explicit constructor with supplied values.
    ///
    /// \param i_origin The origin of the ray.
    /// \param i_direction The direction of the ray.
    /// \param i_maxMagnitude The maximum magnitude that this ray is valid for
    /// \param i_time The time associated with this ray.
    /// \param i_medium The medium containing the origin of this ray.
    explicit constexpr inline Ray( const gm::Vec3f& i_origin,
                                   const gm::Vec3f& i_direction,
                                   float            i_time         = 0.0f,
                                   float            i_maxMagnitude = std::numeric_limits< float >::max(),
                                   const Medium*    i_medium       = nullptr )
        : m_origin( i_origin )
        , m_direction( i_direction )
        , m_time( i_time )
        , m_maxMagnitude( i_maxMagnitude )
        , m_medium( i_medium )
    {
    }

    // --------------------------------------------------------------------- //
    /// \name Accessors
    // --------------------------------------------------------------------- //

    /// Getter for the origin.
    inline const gm::Vec3f& Origin() const
    {
        return m_origin;
    }

    /// Getter for the direction.
    inline const gm::Vec3f& Direction() const
    {
        return m_direction;
    }

    /// Getter for the time.
    inline const float& Time() const
    {
        return m_time;
    }

    /// Getter for the max magnitude.
    inline const float& MaxMagnitude() const
    {
        return m_maxMagnitude;
    }

    /// Setter for the max magnitude.
    inline void SetMaxMagnitude( float i_maxMagnitude ) const
    {
        m_maxMagnitude = i_maxMagnitude;
    }

    /// Getter for the associated medium.
    inline const Medium* Medium() const
    {
        return m_medium;
    }

    // --------------------------------------------------------------------- //
    /// \name Computation
    // --------------------------------------------------------------------- //

    /// Compute the position along this ray with a supplied magnitude \p i_magnitude.
    ///
    /// \param i_magnitude The magnitude or length factor.
    ///
    /// \return The computed position along the ray.
    inline const gm::Vec3f Position( float i_magnitude ) const
    {
        return gm::RayPosition( m_origin, m_direction, i_magnitude );
    }

    // --------------------------------------------------------------------- //
    /// \name Utility
    // --------------------------------------------------------------------- //

    /// Get the string representation.  For debugging purposes.
    ///
    /// \return Descriptive string representing this type instance.
    inline std::string GetString() const
    {
        std::stringstream ss;
        ss << "Ray( ";
        ss << m_origin.GetString();
        ss << ", ";
        ss << m_direction.GetString();
        ss << " )";
        return ss.str();
    }

    /// Check if any of the numeric member values are NaN (not a number).
    ///
    /// \retval true If any of the numeric member values is NaN.
    /// \retval false If none of the numeric member values is NaN.
    inline bool HasNans() const
    {
        return m_origin.HasNans() || m_direction.HasNans() || std::isnan( m_time ) || std::isnan( m_maxMagnitude );
    }

private:
    gm::Vec3f     m_origin;
    gm::Vec3f     m_direction;
    float         m_time         = 0.0f;
    mutable float m_maxMagnitude = std::numeric_limits< float >::max();
    const Medium* medium         = nullptr;
};

/// Operator overload for << to enable writing the string representation of \p i_ray into an output
/// stream \p o_outputStream.
///
/// \param o_outputStream the output stream to write into.
/// \param i_ray the source composite value type.
///
/// \return the output stream.
inline std::ostream& operator<<( std::ostream& o_outputStream, const Ray& i_ray )
{
    o_outputStream << i_ray.GetString();
    return o_outputStream;
}

PBR_NS_CLOSE
