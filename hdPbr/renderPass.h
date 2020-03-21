#pragma once

#include <pxr/imaging/hd/renderPass.h>

#include <pbr/api.h>

#include <hdPbr/renderBuffer.h>

PBR_NAMESPACE_BEGIN

/// \class HdPbrRenderPass
///
/// Represents a single iteration of a render.
class HdPbrRenderPass final : public pxr::HdRenderPass
{
public:
    HdPbrRenderPass( pxr::HdRenderIndex* io_index, const pxr::HdRprimCollection& i_collection );
    virtual ~HdPbrRenderPass();

protected:
    /// Draw the scene with the bound renderpass state.
    ///
    /// \param renderPassState Input parameters (including viewer parameters) for this renderpass.
    /// \param renderTags Which rendertags should be drawn this pass.
    virtual void _Execute( const pxr::HdRenderPassStateSharedPtr& i_renderPassState,
                           const pxr::TfTokenVector&              i_renderTags ) override;

private:
    /// Cached width & height of the viewport, which we are rendering into.
    uint32_t m_width = 0;
    uint32_t m_height = 0;

    /// Color buffer to render RGB pixels into.
    HdPbrRenderBuffer m_colorBuffer;
};

PBR_NAMESPACE_END
