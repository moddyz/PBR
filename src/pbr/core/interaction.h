#pragma once

/// \file core/interaction.h
///
/// Ray interactions.

/// \class Interaction
///
/// Record of a single interaction between a ray and a surface or medium.
class Interaction
{
public:
    /// Check if this interaction is surface-based.
    ///
    /// \retval true If this is a surface-based interaction.
    /// \retval false Otherwise.
    inline bool IsSurfaceInteraction() const
    {
        return m_normal != gm::Vec3f();
    }

    //------------------------------------------------------------------------
    /// \name Members
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

private:
    gm::Vec3f m_position;
    gm::Vec3f m_normal;
    float     m_time;
};

