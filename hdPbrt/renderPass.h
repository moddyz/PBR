#pragma once

#include <pxr/imaging/hd/renderPass.h>

namespace pbrt
{
/// \class HdPbrtRenderPass
///
/// Represents a single render iteration.
class HdPbrtRenderPass final : public pxr::HdRenderPass
{
public:
    HdPbrtRenderPass( pxr::HdRenderIndex* io_index, const pxr::HdRprimCollection& i_collection );
    virtual ~HdPbrtRenderPass();

protected:
    /// Draw the scene with the bound renderpass state.
    ///
    /// \param renderPassState Input parameters (including viewer parameters) for this renderpass.
    /// \param renderTags Which rendertags should be drawn this pass.
    virtual void _Execute( const pxr::HdRenderPassStateSharedPtr& i_renderPassState,
                           const pxr::TfTokenVector&              i_renderTags ) override;
};

} // namespace pbrt
