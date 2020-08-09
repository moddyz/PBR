#pragma once

/// \file core/material.h
///
/// Material class.

#include <pbr/pbr.h>

#include <memory>

PBR_NS_OPEN

/// \class Material
///
/// Manages the appearance of a object.
class Material
{
public:
    virtual ~Material();
};

/// \typedef MaterialSharedPtr
///
/// Convenience type definition.
using MaterialSharedPtr = std::shared_ptr< Material >;

PBR_NS_CLOSE
