#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QObject>

#include "IProjectile.h"

class IScene;

class Projectile : public QObject, public IProjectile
{
    Q_OBJECT

public:
    Projectile( const RenderParam &param, IScene &scene );

public slots:
    void slotTimerUpdate();

protected:
    IScene &m_scene;
};

#endif // PROJECTILE_H
