#include <hdPbr/renderBuffer.h>
#include <hdPbr/renderPass.h>

#include <pxr/imaging/hd/aov.h>
#include <pxr/imaging/hd/renderPassState.h>

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

bool HdPbrRenderPass::IsConverged() const
{
    return m_converged;
}

void HdPbrRenderPass::_Execute( const HdRenderPassStateSharedPtr& i_renderPassState, const TfTokenVector& i_renderTags )
{
    printf( "Executing Render Pass!\n" );

    // Determine whether we need to update the renderer camera.
    GfMatrix4d view = i_renderPassState->GetWorldToViewMatrix();
    GfMatrix4d proj = i_renderPassState->GetProjectionMatrix();
    if ( m_viewMatrix != view || m_projMatrix != proj )
    {
        m_viewMatrix = view;
        m_projMatrix = proj;

        // Update camera.
    }

    // Write values into the color buffer.
    HdRenderPassAovBindingVector aovBindings = i_renderPassState->GetAovBindings();
    for ( const HdRenderPassAovBinding& aovBinding : aovBindings )
    {
        if ( aovBinding.aovName == HdAovTokens->color )
        {
            HdPbrRenderBuffer* renderBuffer = static_cast< HdPbrRenderBuffer* >( aovBinding.renderBuffer );

            // Formats (size of each pixel, and of each pixel component).
            HdFormat format          = renderBuffer->GetFormat();
            size_t   formatSize      = HdDataSizeOfFormat( format );
            HdFormat componentFormat = HdGetComponentFormat( format );
            TF_VERIFY( componentFormat == HdFormatUNorm8 );
            size_t   componentCount  = HdGetComponentCount( format );

            uint8_t* buffer = static_cast< uint8_t* >( renderBuffer->Map() );
            for ( uint32_t y = 0; y < renderBuffer->GetHeight(); ++y )
            {
                for ( uint32_t x = 0; x < renderBuffer->GetWidth(); ++x )
                {
                    uint32_t bufferIndex = ( y * renderBuffer->GetWidth() ) + x;
                    uint8_t* dst         = &buffer[ bufferIndex * formatSize ];
                    for ( size_t c = 0; c < componentCount; ++c )
                    {
                        float value = ( float ) x / ( float ) renderBuffer->GetWidth();
                        dst[ c ] = ( uint8_t )( value * 255.0f );
                    }
                }
            }
        }
    }

    m_converged = true;
}

} // namespace pbr
