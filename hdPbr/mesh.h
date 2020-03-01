#pragma once

#include <pxr/imaging/hd/mesh.h>

namespace pbr
{
/// \class HdPbrMesh
///
/// Representation of a Hydra mesh rprim.
class HdPbrMesh final : public pxr::HdMesh
{
public:
    HdPbrMesh( const pxr::SdfPath& id, const pxr::SdfPath& instancerId = pxr::SdfPath() );
    virtual ~HdPbrMesh() override = default;

    /// This class does not support copying.
    HdPbrMesh( const HdPbrMesh& ) = delete;
    HdPbrMesh& operator=( const HdPbrMesh& ) = delete;

    /// The initial dirty bits
    virtual pxr::HdDirtyBits GetInitialDirtyBitsMask() const override;

    /// Synchronize state by pulling on scene inputs, provided \ref i_dirtyBits.
    /// Sync(s) are called in parallel on Rprims, so access to shared state must be thread-safe.
    virtual void Sync( pxr::HdSceneDelegate* io_sceneDelegate,
                       pxr::HdRenderParam*   i_renderParam,
                       pxr::HdDirtyBits*     i_dirtyBits,
                       const pxr::TfToken&   i_reprToken ) override;

protected:
    /// Initialize the given representation of this Rprim.
    void _InitRepr( const pxr::TfToken& i_reprToken, pxr::HdDirtyBits* i_dirtyBits ) override;

    /// Opportunity to set additional dirty bits based on input bits.
    pxr::HdDirtyBits _PropagateDirtyBits( pxr::HdDirtyBits i_dirtyBits ) const override;
};

} // namespace pbr
