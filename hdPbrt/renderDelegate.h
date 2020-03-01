#pragma once

#include <hdPbrt/api.h>

#include <pxr/imaging/hd/renderDelegate.h>
#include <pxr/imaging/hd/renderThread.h>

namespace pbrt
{
class HdPbrtRenderParam;

class HdPbrtRenderDelegate final : public PXR_NS::HdRenderDelegate
{
public:
    HdPbrtRenderDelegate();
    ~HdPbrtRenderDelegate() override;

    HdPbrtRenderDelegate( const HdPbrtRenderDelegate& ) = delete;
    HdPbrtRenderDelegate& operator=( const HdPbrtRenderDelegate& ) = delete;

    virtual const PXR_NS::TfTokenVector& GetSupportedRprimTypes() const override;
    virtual const PXR_NS::TfTokenVector& GetSupportedSprimTypes() const override;
    virtual const PXR_NS::TfTokenVector& GetSupportedBprimTypes() const override;

    /// Return this delegate's render param, which provides top-level scene state.
    ///   \return An instance of HdEmbreeRenderParam.
    virtual PXR_NS::HdRenderParam* GetRenderParam() const override;

    /// Returns a list of user-configurable render settings, available in the UI.
    virtual PXR_NS::HdRenderSettingDescriptorList GetRenderSettingDescriptors() const override;

private:
    static const PXR_NS::TfTokenVector s_supportedRprimTypes;
    static const PXR_NS::TfTokenVector s_supportedSprimTypes;
    static const PXR_NS::TfTokenVector s_supportedBprimTypes;

    std::unique_ptr< HdPbrtRenderParam >  m_renderParam;
    PXR_NS::HdRenderSettingDescriptorList m_settingDescriptors;
    PXR_NS::HdRenderThread                m_renderThread;
};

} // namespace pbrt
