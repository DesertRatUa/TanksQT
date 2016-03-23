#ifndef PROJECTILESTORE_H
#define PROJECTILESTORE_H

#include "IProjectileStore.h"

class IScene;

class ProjectileStore : public IProjectileStore
{
public:
    ProjectileStore( IScene &scene );

    virtual void Init( const RenderParam &param );
    virtual void CreateProjectile(const Direction direction, const float x, const float y);
    virtual void Update();

    virtual float GetDefaultWidth();
    virtual float GetDefaultHeight();

protected:
    IScene &m_scene;
    const RenderParam *m_renderParams;
};

#endif // PROJECTILESTORE_H
