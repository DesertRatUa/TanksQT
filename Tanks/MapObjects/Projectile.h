#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "IProjectile.h"

class Projectile : public IProjectile
{
public:
    Projectile( const RenderParam &param );
};

#endif // PROJECTILE_H
