#ifndef IPROJECTILESTORE_H
#define IPROJECTILESTORE_H

#include "SceneObjectsStore.h"
#include "MapObjects/Plane.h"

class IProjectileStore : public SceneObjectsStore
{
public:
    virtual ~IProjectileStore() {}

    virtual void CreateProjectile(const Direction direction, const float x, const float y) = 0;

    virtual float GetDefaultWidth() = 0;
    virtual float GetDefaultHeight() = 0;
};

#endif // PROJECTILESTORE_H
