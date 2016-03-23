#include "ProjectileStore.h"
#include "MapObjects/Projectile.h"
#include "IScene.h"

ProjectileStore::ProjectileStore( IScene &scene ) :
    m_scene(scene), m_renderParams(NULL)
{

}

void ProjectileStore::Init( const RenderParam &param )
{
    m_renderParams = &param;
}

 void ProjectileStore::CreateProjectile(const Direction direction, const float x, const float y)
{
     TiProjectilePtr proj( new Projectile( direction, *m_renderParams, m_scene ) );
     proj->SetX( x );
     proj->SetY( y );
     m_objects.push_back(proj);
}

void ProjectileStore::Update()
{
    SceneObjectsStore::Update();
    m_scene.Update();
}

float ProjectileStore::GetDefaultWidth()
{
    return Projectile::GetDefaultWidth();
}

float ProjectileStore::GetDefaultHeight()
{
    return Projectile::GetDefaultHeight();
}
