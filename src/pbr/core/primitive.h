#pragma once

/// \file core/primitive.h
///
/// Primitive class.

#include <pbr/pbr.h>

#include <gm/types/vec3fRange.h>

#include <memory>

PBR_NS_OPEN

// Forward declarations.
class Ray;
class Material;
class SurfaceInteraction;

/// \class Primitive
///
/// Base representation of an object in a scene.
class Primitive
{
public:
    virtual ~Primitive(){};

    // --------------------------------------------------------------------- //
    /// \name Bounding box
    // --------------------------------------------------------------------- //

    /// Compute the world-space bounding box of this primitive.
    ///
    /// \return The world-space bounding box.
    virtual gm::Vec3fRange ComputeWorldBounds() const = 0;

    // --------------------------------------------------------------------- //
    /// \name Ray intersection test
    // --------------------------------------------------------------------- //

    /// Compute ray intersection against this primitive, and capture interaction details.
    ///
    /// \param i_ray The incident ray.
    /// \param o_interaction Details about the interaction of the ray with the surface.
    ///
    /// \return Whether or not the ray intersects this primitive.
    virtual bool Intersect( const Ray& i_ray, SurfaceInteraction& o_interaction ) const = 0;

    /// Check for ray intersection against this primitive.
    ///
    /// \param i_ray The incident ray.
    ///
    /// \return Whether or not the ray intersects this primitive.
    virtual bool IntersectPredicate( const Ray& i_ray ) const;

    // --------------------------------------------------------------------- //
    /// \name Material
    // --------------------------------------------------------------------- //

    /// Get the primitive's associated material.
    ///
    /// \return Associated material.
    virtual const Material* GetMaterial() const = 0;
};

/// \typedef PrimitiveSharedPtr
///
/// Convenience type definition.
using PrimitiveSharedPtr = std::shared_ptr< Primitive >;

PBR_NS_CLOSE
