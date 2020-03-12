#pragma once

#include <pxr/imaging/hd/renderDelegate.h>
#include <pxr/pxr.h>

namespace pbr
{
/// \class HdPbrRenderParam
///
/// Object created by the render delegate to transport top-level scene state
/// to each prim during Sync().
class HdPbrRenderParam final : public pxr::HdRenderParam
{
public:
    HdPbrRenderParam();
    virtual ~HdPbrRenderParam() = default;
};

} // namespace pbr
