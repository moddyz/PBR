#include <hdPbrt/renderPass.h>

PXR_NAMESPACE_USING_DIRECTIVE

namespace pbrt
{
HdPbrtRenderPass::HdPbrtRenderPass( HdRenderIndex* io_index, const HdRprimCollection& i_collection )
    : HdRenderPass( io_index, i_collection )
{
}

HdPbrtRenderPass::~HdPbrtRenderPass()
{
}

void HdPbrtRenderPass::_Execute( const HdRenderPassStateSharedPtr& i_renderPassState,
                                 const TfTokenVector&              i_renderTags )
{
    printf( "Executing Render Pass!\n" );
}

} // namespace pbrt
