#include <hdPbr/renderPass.h>

PXR_NAMESPACE_USING_DIRECTIVE

namespace pbr
{
HdPbrRenderPass::HdPbrRenderPass( HdRenderIndex* io_index, const HdRprimCollection& i_collection )
    : HdRenderPass( io_index, i_collection )
{
}

HdPbrRenderPass::~HdPbrRenderPass()
{
}

void HdPbrRenderPass::_Execute( const HdRenderPassStateSharedPtr& i_renderPassState, const TfTokenVector& i_renderTags )
{
    printf( "Executing Render Pass!\n" );
}

} // namespace pbr
