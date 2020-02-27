#pragma once

#include <pxr/imaging/hd/rendererPlugin.h>

namespace pbrt
{

/// Plugin entry points (construction, destruction) for the pbrt render delegate.
class HdPbrtPlugin final : public PXR_NS::HdRendererPlugin
{
public:
    HdPbrtPlugin()           = default;
    ~HdPbrtPlugin() override = default;

    /// Create a new pbrt render delegate instance.
    HdRenderDelegate* CreateRenderDelegate() override;

    /// Delete a pbrt render delegate instance.
    void DeleteRenderDelegate( HdRenderDelegate* renderDelegate ) override;

    /// Is this plugin supported.
    bool IsSupported() const override
    {
        return true;
    }

private:
    HdPbrtPlugin( const HdPbrtPlugin& ) = delete;
    HdPbrtPlugin& operator=( const HdPbrtPlugin& ) = delete;
};

} // namespace pbrt
