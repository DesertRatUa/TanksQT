#include "ProjectileStore.h"
#include "MapObjects/Projectile.h"

ProjectileStore::ProjectileStore( IScene &scene ) :
    m_scene(scene), m_renderParams(NULL)
{

}

void ProjectileStore::Init( const RenderParam &param )
{
    m_renderParams = &param;
}

 void ProjectileStore::CreateProjectile(float x, float y)
{
     TiProjectilePtr proj( new Projectile( *m_renderParams, m_scene ) );
     proj->SetX( x );
     proj->SetY( y );
     m_objects.push_back(proj);
}
