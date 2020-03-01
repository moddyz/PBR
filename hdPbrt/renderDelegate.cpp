#include <hdPbrt/debugCodes.h>
#include <hdPbrt/renderDelegate.h>
#include <hdPbrt/renderParam.h>
#include <hdPbrt/renderPass.h>
#include <hdPbrt/mesh.h>

#include <pxr/imaging/hd/rprim.h>

PXR_NAMESPACE_USING_DIRECTIVE

namespace pbrt
{
/// Supported Hydra prim types.
const TfTokenVector HdPbrtRenderDelegate::s_supportedRprimTypes = {
    HdPrimTypeTokens->mesh,
};
const TfTokenVector HdPbrtRenderDelegate::s_supportedSprimTypes = {};
const TfTokenVector HdPbrtRenderDelegate::s_supportedBprimTypes = {};

HdPbrtRenderDelegate::HdPbrtRenderDelegate()
    : HdRenderDelegate()
    , m_resourceRegistry( new HdResourceRegistry() )
    , m_renderParam( new HdPbrtRenderParam() )
{
}

HdPbrtRenderDelegate::~HdPbrtRenderDelegate()
{
    // Clean resources.
    m_renderParam.reset();
}

TfTokenVector const& HdPbrtRenderDelegate::GetSupportedRprimTypes() const
{
    return s_supportedRprimTypes;
}

TfTokenVector const& HdPbrtRenderDelegate::GetSupportedSprimTypes() const
{
    return s_supportedSprimTypes;
}

TfTokenVector const& HdPbrtRenderDelegate::GetSupportedBprimTypes() const
{
    return s_supportedBprimTypes;
}

HdRenderParam* HdPbrtRenderDelegate::GetRenderParam() const
{
    return m_renderParam.get();
}

HdRenderSettingDescriptorList HdPbrtRenderDelegate::GetRenderSettingDescriptors() const
{
    return m_settingDescriptors;
}

HdResourceRegistrySharedPtr HdPbrtRenderDelegate::GetResourceRegistry() const
{
    return m_resourceRegistry;
}

HdRenderPassSharedPtr HdPbrtRenderDelegate::CreateRenderPass( HdRenderIndex*           io_index,
                                                              const HdRprimCollection& i_collection )
{
    return HdRenderPassSharedPtr( new HdPbrtRenderPass( io_index, i_collection ) );
}

void HdPbrtRenderDelegate::CommitResources( HdChangeTracker* i_tracker )
{
}

HdRprim*
HdPbrtRenderDelegate::CreateRprim( const TfToken& i_typeId, const SdfPath& i_rprimId, const SdfPath& i_instancerId )
{
    TF_DEBUG( HDPBRT_GENERAL )
        .Msg( "[%s] Create Tiny Rprim type %s id %s\n",
              TF_FUNC_NAME().c_str(),
              i_typeId.GetText(),
              i_rprimId.GetText() );
    if ( i_typeId == HdPrimTypeTokens->mesh )
    {
        return new HdPbrtMesh( i_rprimId, i_instancerId );
    }
    else
    {
        TF_CODING_ERROR( "Unknown Rprim type=%s id=%s", i_typeId.GetText(), i_rprimId.GetText() );
    }
    return nullptr;
}

void HdPbrtRenderDelegate::DestroyRprim( HdRprim* o_rprim )
{
    TF_DEBUG( HDPBRT_GENERAL )
        .Msg( "[%s] Destroy Tiny Rprim id %s\n", TF_FUNC_NAME().c_str(), o_rprim->GetId().GetText() );
    delete o_rprim;
}

HdSprim* HdPbrtRenderDelegate::CreateSprim( const TfToken& i_typeId, const SdfPath& i_sprimId )
{
    TF_CODING_ERROR( "Unknown Sprim type=%s id=%s", i_typeId.GetText(), i_sprimId.GetText() );
    return nullptr;
}

HdSprim* HdPbrtRenderDelegate::CreateFallbackSprim( const TfToken& i_typeId )
{
    TF_CODING_ERROR( "Creating unknown fallback sprim type=%s", i_typeId.GetText() );
    return nullptr;
}

void HdPbrtRenderDelegate::DestroySprim( HdSprim* o_sprim )
{
    TF_CODING_ERROR( "Destroy Sprim not supported" );
}

HdBprim* HdPbrtRenderDelegate::CreateBprim( const TfToken& i_typeId, const SdfPath& i_bprimId )
{
    TF_CODING_ERROR( "Unknown Bprim type=%s id=%s", i_typeId.GetText(), i_bprimId.GetText() );
    return nullptr;
}

HdBprim* HdPbrtRenderDelegate::CreateFallbackBprim( const TfToken& i_typeId )
{
    TF_CODING_ERROR( "Creating unknown fallback bprim type=%s", i_typeId.GetText() );
    return nullptr;
}

void HdPbrtRenderDelegate::DestroyBprim( HdBprim* o_bprim )
{
    TF_CODING_ERROR( "Destroy Bprim not supported" );
}

HdInstancer*
HdPbrtRenderDelegate::CreateInstancer( HdSceneDelegate* i_delegate, const SdfPath& i_id, const SdfPath& i_instancerId )
{
    TF_CODING_ERROR( "Creating Instancer not supported id=%s instancerId=%s", i_id.GetText(), i_instancerId.GetText() );
    return nullptr;
}

void HdPbrtRenderDelegate::DestroyInstancer( HdInstancer* instancer )
{
    TF_CODING_ERROR( "Destroy instancer not supported" );
}

} // namespace pbrt
