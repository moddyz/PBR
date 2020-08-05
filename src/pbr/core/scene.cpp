#include <pbr/core/scene.h>

PBR_NS_OPEN

Scene::Scene( const PrimitiveSharedPtr& i_aggregate )
    : m_aggregate( i_aggregate )
{
}

bool Scene::Intersect( const Ray& i_ray, SurfaceInteraction& o_interaction ) const
{
    return m_aggregate->Intersect( i_ray, o_interaction );
}

bool Scene::IntersectPredicate( const Ray& i_ray ) const
{
    return m_aggregate->IntersectPredicate( i_ray, o_interaction );
}

PBR_NS_CLOSE

