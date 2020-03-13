#include <hdPbr/debugCodes.h>
#include <hdPbr/mesh.h>
#include <hdPbr/renderDelegate.h>
#include <hdPbr/renderParam.h>
#include <hdPbr/renderPass.h>

#include <pxr/imaging/hd/camera.h>
#include <pxr/imaging/hd/rprim.h>

PXR_NAMESPACE_USING_DIRECTIVE

namespace pbr
{
/// Supported Hydra prim types.
const TfTokenVector HdPbrRenderDelegate::s_supportedRprimTypes = {
    HdPrimTypeTokens->mesh,
};
const TfTokenVector HdPbrRenderDelegate::s_supportedSprimTypes = {HdPrimTypeTokens->camera};
const TfTokenVector HdPbrRenderDelegate::s_supportedBprimTypes = {};

HdPbrRenderDelegate::HdPbrRenderDelegate()
    : HdRenderDelegate()
{
}

HdPbrRenderDelegate::HdPbrRenderDelegate( const HdRenderSettingsMap& i_settingsMap )
    : HdRenderDelegate( i_settingsMap )
{
}

HdPbrRenderDelegate::~HdPbrRenderDelegate()
{
    // Clean resources.
    m_renderParam.reset();
}

TfTokenVector const& HdPbrRenderDelegate::GetSupportedRprimTypes() const
{
    return s_supportedRprimTypes;
}

TfTokenVector const& HdPbrRenderDelegate::GetSupportedSprimTypes() const
{
    return s_supportedSprimTypes;
}

TfTokenVector const& HdPbrRenderDelegate::GetSupportedBprimTypes() const
{
    return s_supportedBprimTypes;
}

HdRenderParam* HdPbrRenderDelegate::GetRenderParam() const
{
    return m_renderParam.get();
}

HdRenderSettingDescriptorList HdPbrRenderDelegate::GetRenderSettingDescriptors() const
{
    return m_settingDescriptors;
}

HdResourceRegistrySharedPtr HdPbrRenderDelegate::GetResourceRegistry() const
{
    return m_resourceRegistry;
}

HdRenderPassSharedPtr HdPbrRenderDelegate::CreateRenderPass( HdRenderIndex*           io_index,
                                                             const HdRprimCollection& i_collection )
{
    return HdRenderPassSharedPtr( new HdPbrRenderPass( io_index, i_collection ) );
}

void HdPbrRenderDelegate::CommitResources( HdChangeTracker* i_tracker )
{
}

HdRprim*
HdPbrRenderDelegate::CreateRprim( const TfToken& i_typeId, const SdfPath& i_rprimId, const SdfPath& i_instancerId )
{
    TF_DEBUG( HDPBR_GENERAL )
        .Msg( "[%s] Create Tiny Rprim type %s id %s\n",
              TF_FUNC_NAME().c_str(),
              i_typeId.GetText(),
              i_rprimId.GetText() );
    if ( i_typeId == HdPrimTypeTokens->mesh )
    {
        return new HdPbrMesh( i_rprimId, i_instancerId );
    }
    else
    {
        TF_CODING_ERROR( "Unknown Rprim type=%s id=%s", i_typeId.GetText(), i_rprimId.GetText() );
    }
    return nullptr;
}

void HdPbrRenderDelegate::DestroyRprim( HdRprim* o_rprim )
{
    TF_DEBUG( HDPBR_GENERAL ).Msg( "[%s] Destroy Rprim id %s\n", TF_FUNC_NAME().c_str(), o_rprim->GetId().GetText() );
    delete o_rprim;
}

HdSprim* HdPbrRenderDelegate::CreateSprim( const TfToken& i_typeId, const SdfPath& i_sprimId )
{
    if ( i_typeId == HdPrimTypeTokens->camera )
    {
        return new HdCamera( i_sprimId );
    }
    else
    {
        TF_CODING_ERROR( "Unknown Sprim type=%s id=%s", i_typeId.GetText(), i_sprimId.GetText() );
    }
    return nullptr;
}

HdSprim* HdPbrRenderDelegate::CreateFallbackSprim( const TfToken& i_typeId )
{
    if ( i_typeId == HdPrimTypeTokens->camera )
    {
        return new HdCamera( SdfPath::EmptyPath() );
    }
    else
    {
        TF_CODING_ERROR( "Unknown Fallback Sprim type=%s id=%s", i_typeId.GetText() );
    }
    return nullptr;
}

void HdPbrRenderDelegate::DestroySprim( HdSprim* o_sprim )
{
    TF_CODING_ERROR( "Destroy Sprim not supported" );
}

HdBprim* HdPbrRenderDelegate::CreateBprim( const TfToken& i_typeId, const SdfPath& i_bprimId )
{
    TF_CODING_ERROR( "Unknown Bprim type=%s id=%s", i_typeId.GetText(), i_bprimId.GetText() );
    return nullptr;
}

HdBprim* HdPbrRenderDelegate::CreateFallbackBprim( const TfToken& i_typeId )
{
    TF_CODING_ERROR( "Creating unknown fallback bprim type=%s", i_typeId.GetText() );
    return nullptr;
}

void HdPbrRenderDelegate::DestroyBprim( HdBprim* o_bprim )
{
    TF_CODING_ERROR( "Destroy Bprim not supported" );
}

HdInstancer*
HdPbrRenderDelegate::CreateInstancer( HdSceneDelegate* i_delegate, const SdfPath& i_id, const SdfPath& i_instancerId )
{
    TF_CODING_ERROR( "Creating Instancer not supported id=%s instancerId=%s", i_id.GetText(), i_instancerId.GetText() );
    return nullptr;
}

void HdPbrRenderDelegate::DestroyInstancer( HdInstancer* instancer )
{
    TF_CODING_ERROR( "Destroy instancer not supported" );
}

void HdPbrRenderDelegate::_Setup()
{
    m_renderParam = std::unique_ptr< HdPbrRenderParam >( new HdPbrRenderParam() );
    m_resourceRegistry = boost::shared_ptr< HdResourceRegistry >( new HdResourceRegistry() );
}


} // namespace pbr
