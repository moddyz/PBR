#include <hdPbr/renderPass.h>

PXR_NAMESPACE_USING_DIRECTIVE

namespace pbr
{
HdPbrRenderPass::HdPbrRenderPass( HdRenderIndex* io_index, const HdRprimCollection& i_collection )
    : HdRenderPass( io_index, i_collection )
    , m_colorBuffer( SdfPath::EmptyPath() )
{
}

HdPbrRenderPass::~HdPbrRenderPass()
{
}

void HdPbrRenderPass::_Execute( const HdRenderPassStateSharedPtr& i_renderPassState, const TfTokenVector& i_renderTags )
{
    printf( "Executing Render Pass!\n" );

    //GfVec4f viewport = renderPassState->GetViewport();

    /// Update camera if dirty.
    /// GfMatrix4d worldToViewMatrix = renderPassState->GetWorldToViewMatrix();
    /// GfMatrix4d projectionMatrix = renderPassState->GetProjectionMatrix();

    //m_compositor.UpdateColor(
}

} // namespace pbr
