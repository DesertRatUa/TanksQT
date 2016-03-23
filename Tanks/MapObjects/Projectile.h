#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QObject>

#include "IProjectile.h"

class IScene;

class Projectile : public IProjectile
{
public:
    Projectile( const Direction direction, const RenderParam &param, IScene &scene );
    virtual void Update();

protected:    
    IScene &m_scene;
    float m_speed;
    Direction m_direction;
};

#endif // PROJECTILE_H
