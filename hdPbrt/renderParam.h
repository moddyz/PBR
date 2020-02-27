#pragma once

#include <pxr/pxr.h>
#include <pxr/imaging/hd/renderDelegate.h>

namespace pbrt
{
/// \class HdPbrtRenderParam
///
/// Object created by the render delegate to transport top-level scene state
/// to each prim during Sync().
class HdPbrtRenderParam final : public HdRenderParam
{
public:
    HdPbrtRenderParam();
    virtual ~HdPbrtRenderParam() = default;
};

} // namespace pbrt
