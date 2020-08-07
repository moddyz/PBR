#pragma once

/// \file core/interaction.h
///
/// Ray interactions.

#include <pbr/pbr.h>

PBR_NS_OPEN

/// \class Interaction
///
/// Record of a single interaction between a ray and a surface or medium.
class Interaction
{
public:
    //------------------------------------------------------------------------
    /// \name Construction
    //------------------------------------------------------------------------

    /// Default constructor.
    Interaction() = default;

    /// Explicit constructor with position, normal, and time.
    ///
    /// \param i_position The worldspace position of interaction.
    /// \param i_normal The norma
    inline explicit Interaction( const gm::Vec3f& i_position, const gm::Vec3f& i_normal, float i_time )
        : m_position( i_position )
        , m_normal( i_normal )
        , m_time( i_time )
    {
    }

    virtual ~Interaction(){};

    //------------------------------------------------------------------------
    /// \name Member access
    //------------------------------------------------------------------------

    /// Get the point of interaction.
    ///
    /// \return The interaction point.
    inline const gm::Vec3f& GetPosition() const
    {
        return m_position;
    }

    /// Get the normal at the point of interaction (for surfaces only).
    ///
    /// \return The interaction normal vector.
    inline const gm::Vec3f& GetNormal() const
    {
        return m_normal;
    }

    /// Get the associated time.
    ///
    /// \return The time of interaction.
    inline float GetTime() const
    {
        return m_time;
    }

    //------------------------------------------------------------------------
    /// \name Introspection
    //------------------------------------------------------------------------

    /// Check if this interaction is surface-based.
    ///
    /// \retval true If this is a surface-based interaction.
    /// \retval false Otherwise.
    inline bool IsSurfaceInteraction() const
    {
        return m_normal != gm::Vec3f();
    }

private:
    gm::Vec3f m_position;
    gm::Vec3f m_normal;
    float     m_time = 0.0f;
};

PBR_NS_CLOSE
