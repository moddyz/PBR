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

    /// Constructor with object-to-world transformation and its inverse.
    ///
    /// \param i_objectToWorld Object-to-world transform.
    /// \param i_worldToObject World-to-object transform.
    explicit Shape( const Transform& i_objectToWorld, const Transform& i_worldToObject );

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

    /// Get the object-to-world transform associated with this shape.
    ///
    /// \return The object-to-world transform.
    const Transform& ObjectToWorldTransform() const
    {
        return m_objectToWorld;
    }

    /// Get the world-to-object transform associated with this shape.
    ///
    /// \return The world-to-object transform.
    const Transform& WorldToObjectTransform() const
    {
        return m_worldToObject;
    }

    // --------------------------------------------------------------------- //
    /// \name Intersections
    // --------------------------------------------------------------------- //

private:
    const Transform& m_objectToWorld;
    const Transform& m_worldToObject;
};

PBR_NS_CLOSE
