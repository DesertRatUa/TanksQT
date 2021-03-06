#ifndef TANK_H
#define TANK_H

#include "ITank.h"

class IScene;

class Tank : public ITank
{
public:
    Tank( const RenderParam &param, IScene &scene );
    virtual ~Tank() {}

    virtual void MoveUp();
    virtual void MoveDown();
    virtual void MoveLeft();
    virtual void MoveRight();
    virtual void Shoot();

protected:
    float CalculateStep( const Direction direction ) const;

    IScene &m_scene;
};

#endif // TANK_H
