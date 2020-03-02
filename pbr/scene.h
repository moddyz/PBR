#pragma once

namespace pbr
{
/// Top-level container of primitives contributing to a render.
///
class Scene
{
public:
    Scene();
    virtual Scene() {};

    /// Scene cannot be copied.
    Scene( const Scene& ) = delete;
    Scene& operator=( const Scene& ) = delete;
};

} // namespace pbr
