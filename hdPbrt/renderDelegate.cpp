#include <hdPbrt/renderDelegate.h>

namespace pbrt
{
const TfTokenVector HdPbrtRenderDelegate::s_supportedRprimTypes = {
    HdPrimTypeTokens->mesh,
};

const TfTokenVector HdPbrtRenderDelegate::s_supportedSprimTypes = {
    HdPrimTypeTokens->camera,
    HdPrimTypeTokens->extComputation,
};

const TfTokenVector HdPbrtRenderDelegate::s_supportedBprimTypes = {
    HdPrimTypeTokens->renderBuffer,
};

HdPbrtRenderDelegate::HdPbrtRenderDelegate()
    : HdRenderDelegate()
{
    m_renderThread.StartThread();
}

HdPbrtRenderDelegate::~HdPbrtRenderDelegate()
{
    // Stop rendering.
    m_renderThread.StopThread();

    // Clean resources.
    m_renderParam.reset();
}

HdRenderParam* HdPbrtRenderDelegate::GetRenderParam() const
{
    return m_renderParam.get();
}

HdRenderSettingDescriptorList HdPbrtRenderDelegate::GetRenderSettingDescriptors() const
{
    return m_settingDescriptors;
}

} // namespace pbrt
