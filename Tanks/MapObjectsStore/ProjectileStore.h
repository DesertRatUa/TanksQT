#ifndef PROJECTILESTORE_H
#define PROJECTILESTORE_H
#include "SceneObjectsStore.h"

class ProjectileStore : public SceneObjectsStore
{
public:
    ProjectileStore();

    virtual void Init( const RenderParam &param );
};

#endif // PROJECTILESTORE_H
