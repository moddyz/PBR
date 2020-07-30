#pragma once

/// \file core/shape.h
///
/// Shape interface.

#include <pbr/pbr.h>

#include <gm/types/vec3fRange.h>

PBR_NS_OPEN

// Forward declarations.
class Transform;

/// \class Shape
///
/// The interface for providing the raw geometric information of a primitive.
class Shape
{
public:
    /// Get the object-space bounding box of this shape.
    ///
    /// \return The object-space bounding box.
    virtual gm::Vec3fRange ObjectBounds() const = 0;

    /// Get the world-space bounding box of this shape.
    ///
    /// \return The world-space bounding box.
    gm::Vec3fRange WorldBounds() const;

private:
    Transform* m_objectToWorld;
};

PBR_NS_CLOSE
