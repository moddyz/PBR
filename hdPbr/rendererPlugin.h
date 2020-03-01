#pragma once

#include <pxr/imaging/hd/rendererPlugin.h>

namespace pbr
{
/// Plugin entry points (construction, destruction) for the pbr render delegate.
class HdPbrRendererPlugin final : public pxr::HdRendererPlugin
{
public:
    HdPbrRendererPlugin()           = default;
    ~HdPbrRendererPlugin() override = default;

    /// Cannot copy.
    HdPbrRendererPlugin( const HdPbrRendererPlugin& ) = delete;
    HdPbrRendererPlugin& operator=( const HdPbrRendererPlugin& ) = delete;

    /// Create a new pbr render delegate instance.
    virtual pxr::HdRenderDelegate* CreateRenderDelegate() override;

    /// Delete a pbr render delegate instance.
    virtual void DeleteRenderDelegate( pxr::HdRenderDelegate* renderDelegate ) override;

    /// Is this plugin supported?
    virtual bool IsSupported() const override;
};

} // namespace pbr
