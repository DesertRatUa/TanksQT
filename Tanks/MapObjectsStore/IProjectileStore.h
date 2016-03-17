#ifndef IPROJECTILESTORE_H
#define IPROJECTILESTORE_H

#include "SceneObjectsStore.h"

class IProjectileStore : public SceneObjectsStore
{
public:
    virtual ~IProjectileStore() {}

    virtual void CreateProjectile(float x, float y) = 0;
};

#endif // PROJECTILESTORE_H
