#pragma once

/// \file core/surfaceInteraction.h
///
/// Ray-surface interaction.

#include <pbr/core/interaction.h>

PBR_NS_OPEN

/// \class SurfaceInteraction
///
/// Record of a single interaction between a ray and a surface or medium.
class SurfaceInteraction : public Interaction
{
public:
    SurfaceInteraction()
    {
    }
};

PBR_NS_CLOSE
