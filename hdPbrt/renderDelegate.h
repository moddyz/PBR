#pragma once

#include <hdPbrt/api.h>

#include <pxr/imaging/hd/renderDelegate.h>
#include <pxr/imaging/hd/renderThread.h>

namespace pbrt
{
class HdPbrtRenderParam;

class HdPbrtRenderDelegate final : public HdRenderDelegate
{
public:
    HdPbrtRenderDelegate();
    ~HdPbrtRenderDelegate() override;

    HdPbrtRenderDelegate( const HdPbrtRenderDelegate& ) = delete;
    HdPbrtRenderDelegate& operator=( const HdPbrtRenderDelegate& ) = delete;

    const TfTokenVector& GetSupportedRprimTypes() const override;
    const TfTokenVector& GetSupportedSprimTypes() const override;
    const TfTokenVector& GetSupportedBprimTypes() const override;

    /// Return this delegate's render param, which provides top-level scene state.
    ///   \return An instance of HdEmbreeRenderParam.
    virtual HdRenderParam* GetRenderParam() const override;

    /// Returns a list of user-configurable render settings, available in the UI.
    virtual HdRenderSettingDescriptorList GetRenderSettingDescriptors() const override;



private:
    static const TfTokenVector s_supportedRprimTypes;
    static const TfTokenVector s_supportedSprimTypes;
    static const TfTokenVector s_supportedBprimTypes;

    std::unique_ptr< HdPbrtRenderParam >  m_renderParam;
    PXR_NS::HdRenderSettingDescriptorList m_settingDescriptors;
    HdRenderThread                        m_renderThread;
};

} // namespace pbrt
