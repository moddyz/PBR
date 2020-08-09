#pragma once

/// \file core/shape.h
///
/// Geometric shape interface.

#include <pbr/pbr.h>

#include <gm/types/vec3fRange.h>

#include <memory>

PBR_NS_OPEN

// Forward declarations.
class Transform;
class Ray;
class SurfaceInteraction;

/// \class Shape
///
/// The interface for the geometric component of a primitive.
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
    virtual ~Shape(){};

    // --------------------------------------------------------------------- //
    /// \name Bounding box
    // --------------------------------------------------------------------- //

    /// Get the object-space bounding box of this shape.
    ///
    /// \return The object-space bounding box.
    virtual gm::Vec3fRange ComputeObjectBounds() const = 0;

    /// Get the world-space bounding box of this shape.
    ///
    /// \return The world-space bounding box.
    virtual gm::Vec3fRange ComputeWorldBounds() const;

    // --------------------------------------------------------------------- //
    /// \name Transforms
    // --------------------------------------------------------------------- //

    /// Get the object-to-world transform associated with this shape.
    ///
    /// \return The object-to-world transform.
    inline const Transform& GetObjectToWorld() const
    {
        return m_objectToWorld;
    }

    /// Get the world-to-object transform associated with this shape.
    ///
    /// \return The world-to-object transform.
    inline const Transform& GetWorldToObject() const
    {
        return m_worldToObject;
    }

    // --------------------------------------------------------------------- //
    /// \name Ray intersection test
    // --------------------------------------------------------------------- //

    /// Compute ray intersection against this shape, and capture interaction details.
    ///
    /// \param i_ray The incident ray.
    /// \param o_rayMagnitude The magnitude of the ray which a intersection occurs.
    /// \param o_interaction Details about the interaction of the ray with the surface.
    ///
    /// \return Whether or not the ray intersects this shape.
    virtual bool Intersect( const Ray& i_ray, float& o_rayMagnitude, SurfaceInteraction& o_interaction ) const = 0;

    /// Check for ray intersection against this shape.
    ///
    /// \param i_ray The incident ray.
    ///
    /// \return Whether or not the ray intersects this shape.
    virtual bool IntersectPredicate( const Ray& i_ray ) const;

    // --------------------------------------------------------------------- //
    /// \name Surface area
    // --------------------------------------------------------------------- //

    /// Compute the surface area of this shape.
    virtual float ComputeSurfaceArea() const = 0;

private:
    const Transform& m_objectToWorld;
    const Transform& m_worldToObject;
};

/// \typedef ShapeSharedPtr
using ShapeSharedPtr = std::shared_ptr< Shape >;

PBR_NS_CLOSE
