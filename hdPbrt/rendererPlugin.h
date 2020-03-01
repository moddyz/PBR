#pragma once

#include <pxr/imaging/hd/rendererPlugin.h>

namespace pbrt
{
/// Plugin entry points (construction, destruction) for the pbrt render delegate.
class HdPbrtRendererPlugin final : public pxr::HdRendererPlugin
{
public:
    HdPbrtRendererPlugin()           = default;
    ~HdPbrtRendererPlugin() override = default;

    /// Cannot copy.
    HdPbrtRendererPlugin( const HdPbrtRendererPlugin& ) = delete;
    HdPbrtRendererPlugin& operator=( const HdPbrtRendererPlugin& ) = delete;

    /// Create a new pbrt render delegate instance.
    virtual pxr::HdRenderDelegate* CreateRenderDelegate() override;

    /// Delete a pbrt render delegate instance.
    virtual void DeleteRenderDelegate( pxr::HdRenderDelegate* renderDelegate ) override;

    /// Is this plugin supported?
    virtual bool IsSupported() const override;
};

} // namespace pbrt
