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
/// The interface for the raw geometric features of a primitive.
class Shape
{
public:
    // --------------------------------------------------------------------- //
    /// \name Construction
    // --------------------------------------------------------------------- //

    /// Constructor with object to world transformation.
    ///
    /// \param i_objectToWorld Object-to-world transform.
    explicit Shape( const Transform& i_objectToWorld );

    // Virtual de-constructor.
    ~Shape() {};

    // --------------------------------------------------------------------- //
    /// \name Bounding box
    // --------------------------------------------------------------------- //

    /// Get the object-space bounding box of this shape.
    ///
    /// \return The object-space bounding box.
    virtual gm::Vec3fRange ObjectBounds() const = 0;

    /// Get the world-space bounding box of this shape.
    ///
    /// \return The world-space bounding box.
    gm::Vec3fRange WorldBounds() const;

    // --------------------------------------------------------------------- //
    /// \name Transforms
    // --------------------------------------------------------------------- //

    /// Get the object-space to world-space transform.
    ///
    /// \return The object-to-world transform.
    const Transform& ObjectToWorldTransform() const
    {
        return m_objectToWorld;
    }

    // --------------------------------------------------------------------- //
    /// \name Intersections
    // --------------------------------------------------------------------- //

private:
    const Transform& m_objectToWorld;
};

PBR_NS_CLOSE
