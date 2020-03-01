#include <hdPbrt/debugCodes.h>
#include <hdPbrt/mesh.h>

PXR_NAMESPACE_USING_DIRECTIVE

namespace pbrt
{
HdPbrtMesh::HdPbrtMesh( SdfPath const& id, SdfPath const& instancerId )
    : HdMesh( id, instancerId )
{
}

HdDirtyBits HdPbrtMesh::GetInitialDirtyBitsMask() const
{
    return HdChangeTracker::Clean | HdChangeTracker::DirtyTransform;
}

HdDirtyBits HdPbrtMesh::_PropagateDirtyBits( HdDirtyBits i_dirtyBits ) const
{
    return i_dirtyBits;
}

void HdPbrtMesh::_InitRepr( const TfToken& i_reprToken, HdDirtyBits* i_dirtyBits )
{
}

void HdPbrtMesh::Sync( HdSceneDelegate* io_sceneDelegate,
                       HdRenderParam*   i_renderParam,
                       HdDirtyBits*     i_dirtyBits,
                       const TfToken&   i_reprToken )
{
    TF_DEBUG( HDPBRT_GENERAL ).Msg( "[%s] Sync Tiny Mesh id=%s\n", TF_FUNC_NAME().c_str(), GetId().GetText() );
}

} // namespace pbrt
