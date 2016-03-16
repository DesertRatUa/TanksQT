#include "ProjectileStore.h"
#include "MapObjects/Projectile.h"

ProjectileStore::ProjectileStore()
{

}

void ProjectileStore::Init( const RenderParam &param )
{
   TiProjectilePtr proj( new Projectile(param) );
   proj->SetX( 300 );
   proj->SetY( 300 );
   m_objects.push_back(proj);
}
