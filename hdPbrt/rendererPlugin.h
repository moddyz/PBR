#pragma once

#include <pxr/imaging/hd/rendererPlugin.h>

namespace pbrt
{
/// Plugin entry points (construction, destruction) for the pbrt render delegate.
class HdPbrtRendererPlugin final : public PXR_NS::HdRendererPlugin
{
public:
    HdPbrtRendererPlugin()           = default;
    ~HdPbrtRendererPlugin() override = default;

    /// Cannot copy.
    HdPbrtRendererPlugin( const HdPbrtRendererPlugin& ) = delete;
    HdPbrtRendererPlugin& operator=( const HdPbrtRendererPlugin& ) = delete;

    /// Create a new pbrt render delegate instance.
    PXR_NS::HdRenderDelegate* CreateRenderDelegate() override;

    /// Delete a pbrt render delegate instance.
    void DeleteRenderDelegate( PXR_NS::HdRenderDelegate* renderDelegate ) override;

    /// Is this plugin supported.
    bool IsSupported() const override
    {
        return true;
    }
};

} // namespace pbrt
