#ifndef IPROJECTILE_H
#define IPROJECTILE_H

#include "Plane.h"

class IProjectile : public Plane
{
public:
    IProjectile( const RenderParam &param ) : Plane(param) {}
    virtual ~IProjectile() {}
};

typedef std::shared_ptr<IProjectile> TiProjectilePtr;

#endif // BLOCKOFBRICKWALL_H
