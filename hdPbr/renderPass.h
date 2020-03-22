#pragma once

#include <pxr/imaging/hd/renderPass.h>
#include <pxr/base/gf/matrix4d.h>

#include <pbr/api.h>

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

    /// Determine whether the sample buffer has enough samples, to be considered final.
    virtual bool IsConverged() const override;

private:
    // The view matrix: world space to camera space
    pxr::GfMatrix4d m_viewMatrix;

    // The projection matrix: camera space to NDC space
    pxr::GfMatrix4d m_projMatrix;

    // Is converged?
    bool m_converged = false;
};

PBR_NAMESPACE_END
