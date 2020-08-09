#pragma once

/// \file core/geometricPrimitive.h
///
/// Geometric primitive class.

#include <pbr/core/material.h>
#include <pbr/core/primitive.h>
#include <pbr/core/shape.h>

PBR_NS_OPEN

/// \class GeometricPrimitive
///
/// Representation of a object in the scene which has an associated geometry.
class GeometricPrimitive : public Primitive
{
public:
    // --------------------------------------------------------------------- //
    /// \name Construction
    // --------------------------------------------------------------------- //

    /// Parameterized construction.
    ///
    /// \param i_shape The geometric shape associated with this primitive.
    /// \param i_material The material associated with this primitive.
    GeometricPrimitive( const ShapeSharedPtr& i_shape, const MaterialSharedPtr& i_material );

    // --------------------------------------------------------------------- //
    /// \name Bounding box
    // --------------------------------------------------------------------- //

    virtual gm::Vec3fRange ComputeWorldBounds() const override;

    // --------------------------------------------------------------------- //
    /// \name Ray intersection test
    // --------------------------------------------------------------------- //

    virtual bool Intersect( const Ray& i_ray, SurfaceInteraction& o_interaction ) const override;
    virtual bool IntersectPredicate( const Ray& i_ray ) const override;

private:
    ShapeSharedPtr    m_shape;
    MaterialSharedPtr m_material;
};

PBR_NS_CLOSE
