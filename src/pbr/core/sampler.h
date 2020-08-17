#pragma once

/// \file core/sampler.h
///
/// Sampler class.

#include <pbr/core/integrator.h>

#include <memory>

PBR_NS_OPEN

/// \class Sampler
///
/// Base class for choosing the positions on the image plane from which rays are traced.
class Sampler
{
public:
    // --------------------------------------------------------------------- //
    /// \name Construction
    // --------------------------------------------------------------------- //

    /// Construct this sampler with a specified
    Sampler( int i_samplesPerPixel );

    // Virtual d'tor.
    virtual ~Sampler();
};

/// \typedef SamplerSharedPtr
///
/// Convenience type definition.
using SamplerSharedPtr = std::shared_ptr< Sampler >;

PBR_NS_CLOSE
