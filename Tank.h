#ifndef TANK_H
#define TANK_H
#include "TankRender.h"
#include "ITank.h"

class IScene;

class Tank : public ITank
{
public:
    Tank( IScene &scene );

    virtual void Init( RenderParam &param );
    virtual void Draw();

    virtual void MoveUp();
    virtual void MoveDown();
    virtual void MoveLeft();
    virtual void MoveRight();

protected:
    float CalculateStep( const TankRender::Direction direction ) const;

    IScene &m_scene;
    std::auto_ptr<TankRender> m_render;
};

#endif // TANK_H
