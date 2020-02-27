#include <hdPbrt/renderDelegate.h>
#include <hdPbrt/rendererPlugin.h>

#include <pxr/imaging/hd/rendererPluginRegistry.h>

namespace pbrt
{
PXR_NAMESPACE_USING_DIRECTIVE

TF_REGISTRY_FUNCTION( TfType )
{
    HdRendererPluginRegistry::Define< HdPbrtPlugin >();
}

HdRenderDelegate* HdPbrtPlugin::CreateRenderDelegate()
{
    return new HdPbrtDelegate();
}

void HdPbrtPlugin::DeleteRenderDelegate( HdRenderDelegate* renderDelegate )
{
    delete renderDelegate;
}

} // namespace pbrt
