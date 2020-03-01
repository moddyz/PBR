#pragma once

#include <hdPbr/api.h>

#include <pxr/imaging/hd/renderDelegate.h>
#include <pxr/imaging/hd/resourceRegistry.h>

namespace pbr
{
class HdPbrRenderParam;

class HdPbrRenderDelegate final : public pxr::HdRenderDelegate
{
public:
    HdPbrRenderDelegate();
    ~HdPbrRenderDelegate() override;

    HdPbrRenderDelegate( const HdPbrRenderDelegate& ) = delete;
    HdPbrRenderDelegate& operator=( const HdPbrRenderDelegate& ) = delete;

    /// Query supported hydra prim types.
    virtual const pxr::TfTokenVector& GetSupportedRprimTypes() const override;
    virtual const pxr::TfTokenVector& GetSupportedSprimTypes() const override;
    virtual const pxr::TfTokenVector& GetSupportedBprimTypes() const override;

    /// Return this delegate's render param, which provides top-level scene state.
    ///   \return An instance of HdEmbreeRenderParam.
    virtual pxr::HdRenderParam* GetRenderParam() const override;

    /// Returns a list of user-configurable render settings, available in the UI.
    virtual pxr::HdRenderSettingDescriptorList GetRenderSettingDescriptors() const override;

    /// Get the resource registry.
    virtual pxr::HdResourceRegistrySharedPtr GetResourceRegistry() const override;

    /// Create render pass.
    virtual pxr::HdRenderPassSharedPtr CreateRenderPass( pxr::HdRenderIndex*           io_index,
                                                            const pxr::HdRprimCollection& i_collection ) override;

    /// Create an instancer.
    virtual pxr::HdInstancer* CreateInstancer( pxr::HdSceneDelegate* i_delegate,
                                                  const pxr::SdfPath&   i_id,
                                                  const pxr::SdfPath&   i_instancerId ) override;

    /// Destroy an instancer.
    virtual void DestroyInstancer( pxr::HdInstancer* o_instancer ) override;

    /// Create a new Rprim.
    virtual pxr::HdRprim* CreateRprim( const pxr::TfToken& i_typeId,
                                          const pxr::SdfPath& i_rprimId,
                                          const pxr::SdfPath& i_instancerId ) override;

    virtual void DestroyRprim( pxr::HdRprim* i_rprim ) override;

    /// Create a new Sprim.
    virtual pxr::HdSprim* CreateSprim( const pxr::TfToken& i_typeId, const pxr::SdfPath& i_sprimId ) override;

    /// TODO.
    virtual pxr::HdSprim* CreateFallbackSprim( const pxr::TfToken& i_typeId ) override;

    /// Destroy an existing Sprim.
    virtual void DestroySprim( pxr::HdSprim* i_sprim ) override;

    /// Create a new buffer prim.
    virtual pxr::HdBprim* CreateBprim( const pxr::TfToken& i_typeId, const pxr::SdfPath& i_bprimId ) override;

    /// Create a fallback buffer prim.
    virtual pxr::HdBprim* CreateFallbackBprim( const pxr::TfToken& i_typeId ) override;

    /// Destroy an existing Bprim.
    virtual void DestroyBprim( pxr::HdBprim* bprim ) override;

    /// Do work.
    virtual void CommitResources( pxr::HdChangeTracker* tracker ) override;

private:
    static const pxr::TfTokenVector s_supportedRprimTypes;
    static const pxr::TfTokenVector s_supportedSprimTypes;
    static const pxr::TfTokenVector s_supportedBprimTypes;

    std::unique_ptr< HdPbrRenderParam >  m_renderParam;
    pxr::HdRenderSettingDescriptorList m_settingDescriptors;

    pxr::HdResourceRegistrySharedPtr m_resourceRegistry;
};

} // namespace pbr
