#pragma once

/// \file shapes/sphere.h
///
/// Sphere geometric shape.

#include <pbr/core/shape.h>

#include <gm/types/vec3fRange.h>

PBR_NS_OPEN

/// \class Sphere
///
/// A 3D geometric surface where the distance between every surface point
/// and its origin is a fixed \p radius.
class Sphere : public Shape
{
public:
    // --------------------------------------------------------------------- //
    /// \name Construction
    // --------------------------------------------------------------------- //

    /// Parameterized constructor.
    ///
    /// \param i_objectToWorld Object-to-world transform.
    /// \param i_worldToObject World-to-object transform.
    /// \param i_radius The radius of the sphere.
    explicit Sphere( const Transform& i_objectToWorld, const Transform& i_worldToObject, float i_radius );

    // --------------------------------------------------------------------- //
    /// \name Bounding box
    // --------------------------------------------------------------------- //

    virtual gm::Vec3fRange ComputeObjectBounds() const override;

private:
    float m_radius = 0.0f;
};

PBR_NS_CLOSE
