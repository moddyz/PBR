#include <hdPbrt/renderDelegate.h>
#include <hdPbrt/rendererPlugin.h>

#include <pxr/imaging/hd/rendererPluginRegistry.h>

PXR_NAMESPACE_USING_DIRECTIVE

TF_REGISTRY_FUNCTION( TfType )
{
    HdRendererPluginRegistry::Define< pbrt::HdPbrtRendererPlugin >();
}

namespace pbrt
{

HdRenderDelegate* HdPbrtRendererPlugin::CreateRenderDelegate()
{
    return new HdPbrtRenderDelegate();
}

void HdPbrtRendererPlugin::DeleteRenderDelegate( HdRenderDelegate* renderDelegate )
{
    delete renderDelegate;
}

bool HdPbrtRendererPlugin::IsSupported() const
{
    return true;
}

} // namespace pbrt
