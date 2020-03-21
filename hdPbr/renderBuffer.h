#pragma once

#include <pxr/imaging/hd/renderBuffer.h>
#include <pxr/base/gf/vec3i.h>

#include <pbr/api.h>

PBR_NAMESPACE_BEGIN

/// \class HdPbrRenderBuffer
///
/// A block of memory which we are rendering into.
class HdPbrRenderBuffer : public pxr::HdRenderBuffer
{
public:
    HdPbrRenderBuffer( const pxr::SdfPath& i_bprimId );

    /// Allocate a new buffer with the given dimensions and format.
    virtual bool Allocate( const pxr::GfVec3i& i_dimensions, pxr::HdFormat i_format, bool i_multiSampled ) override;

    /// Accessor for buffer width.
    virtual unsigned int GetWidth() const override;

    /// Accessor for buffer height.
    virtual unsigned int GetHeight() const override;

    /// Accessor for buffer depth.
    virtual unsigned int GetDepth() const override;

    /// Accessor for buffer format.
    virtual pxr::HdFormat GetFormat() const override;

    /// Accessor for the buffer multisample state.
    virtual bool IsMultiSampled() const override;

    /// Map the buffer for reading/writing. The control flow should be Map(),
    /// before any I/O, followed by memory access, followed by Unmap() when
    /// done.
    virtual void* Map() override;

    /// Unmap the buffer.
    virtual void Unmap() override;

    /// Return whether any clients have this buffer mapped currently.
    virtual bool IsMapped() const override;

    /// Is the buffer converged?
    virtual bool IsConverged() const override;

    /// Set the convergence.
    void SetConverged( bool i_converged );

    /// Resolve the sample buffer into final values.
    virtual void Resolve() override;

private:
    // Release any allocated resources.
    virtual void _Deallocate() override;

    // Buffer dimensions.
    pxr::GfVec3i m_dimensions = pxr::GfVec3i( 0, 0, 0 );

    // Buffer format.
    pxr::HdFormat m_format = pxr::HdFormatInvalid;

    // The actual buffer of bytes.
    std::vector< uint8_t > m_buffer;

    // The number of callers mapping this buffer.
    std::atomic< int > m_mappers;

    // Whether the buffer has been marked as converged.
    std::atomic< bool > m_converged;
};

PBR_NAMESPACE_END
