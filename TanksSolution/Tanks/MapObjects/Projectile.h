#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QObject>

#include "IProjectile.h"

class IScene;

class Projectile : public IProjectile
{
public:
    Projectile( const Direction direction, const RenderParam &param, IScene &scene );
    virtual void Update( const float frameTime );

protected:    
    IScene &m_scene;
    Direction m_direction;
};

#endif // PROJECTILE_H
