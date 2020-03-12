#include <hdPbr/debugCodes.h>
#include <hdPbr/mesh.h>

PXR_NAMESPACE_USING_DIRECTIVE

namespace pbr
{
HdPbrMesh::HdPbrMesh( SdfPath const& id, SdfPath const& instancerId )
    : HdMesh( id, instancerId )
{
}

HdDirtyBits HdPbrMesh::GetInitialDirtyBitsMask() const
{
    return HdChangeTracker::Clean | HdChangeTracker::DirtyTransform;
}

HdDirtyBits HdPbrMesh::_PropagateDirtyBits( HdDirtyBits i_dirtyBits ) const
{
    return i_dirtyBits;
}

void HdPbrMesh::_InitRepr( const TfToken& i_reprToken, HdDirtyBits* i_dirtyBits )
{
}

void HdPbrMesh::Sync( HdSceneDelegate* io_sceneDelegate,
                      HdRenderParam*   i_renderParam,
                      HdDirtyBits*     i_dirtyBits,
                      const TfToken&   i_reprToken )
{
    TF_DEBUG( HDPBR_GENERAL ).Msg( "[%s] Sync Tiny Mesh id=%s\n", TF_FUNC_NAME().c_str(), GetId().GetText() );
}

} // namespace pbr
