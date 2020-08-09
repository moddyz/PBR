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
class GeometricPrimitive
{
public:
    GeometricPrimitive( const ShapeSharedPtr& i_shape, const MaterialSharedPtr& i_material );

private:
    ShapeSharedPtr    m_shape;
    MaterialSharedPtr m_material;
};

PBR_NS_CLOSE
