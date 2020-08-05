#pragma once

/// \file core/primitive.h
///
/// Primitive class.

#include <pbr/pbr.h>

PBR_NS_OPEN

/// \class Primitive
///
/// Abstract base class representation of a single renderable object in a scene.
class Primitive
{
public:
    /// Compute the world-space bounding box of this primitive.
    ///
    /// \return The world-space bounding box.
    virtual gm::Vec3fRange ComputeWorldBounds() const = 0;
};

/// \typedef PrimitiveSharedPtr
using PrimitiveSharedPtr = std::shared_ptr< Primitive >;

PBR_NS_CLOSE
