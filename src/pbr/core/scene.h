#pragma once

/// \file core/scene.h
///
/// Scene class.

#include <pbr/core/primitive.h>

PBR_NS_OPEN

// Forward declarations.
class Ray;
class SurfaceInteraction;

/// \class Scene
///
/// A collection of primitives and lights to render.
class Scene
{
public:
    // --------------------------------------------------------------------- //
    /// \name Construction
    // --------------------------------------------------------------------- //

    /// Construct this scene with a single aggregate primitive.
    ///
    /// \param i_aggregate The aggregating primitive.
    explicit Scene( const PrimitiveSharedPtr& i_aggregate );

    // --------------------------------------------------------------------- //
    /// \name Intersection
    // --------------------------------------------------------------------- //

    /// Compute ray intersection against this scene, and capture
    ///
    /// \param i_ray The incident ray.
    /// \param o_interaction Details about the interaction of the ray with a surface.
    ///
    /// \return Whether or not the ray intersects any primitives in this scene.
    virtual bool Intersect( const Ray& i_ray, SurfaceInteraction& o_interaction ) const;

    /// Check for ray intersection against this scene, without capturing interaction details.
    ///
    /// \param i_ray The incident ray.
    ///
    /// \return Whether or not the ray intersects any primitives in this scene.
    virtual bool IntersectPredicate( const Ray& i_ray ) const;

private:
    PrimitiveSharedPtr m_aggregate;
};

PBR_NS_CLOSE
