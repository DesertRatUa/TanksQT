#include <assert.h>

#include "Tank.h"
#include "IScene.h"
#include "IColission.h"
#include "MapObjectsStore/IOuterBoundaryStore.h"

static const float max_step = 10.0f;

Tank::Tank( const RenderParam &param, IScene &scene ) :
    m_scene( scene ), ITank(param)
{
}

void Tank::MoveUp()
{
    float step = CalculateStep( TankRender::Up );
    if (step > 0)
        SetY( GetY() - step );
    SetDirection( TankRender::Up );
}

void Tank::MoveDown()
{
    float step = CalculateStep( TankRender::Down );
    if (step > 0)
        SetY( GetY() + step );
    SetDirection( TankRender::Down );
}

void Tank::MoveLeft()
{
    float step = CalculateStep( TankRender::Left );
    if ( step > 0 )
        SetX( GetX() - step );
    SetDirection( TankRender::Left );
}

void Tank::MoveRight()
{
    float step = CalculateStep( TankRender::Right );
    if ( step > 0 )
        SetX( GetX() + step );
    SetDirection( TankRender::Right );
}

float Tank::CalculateStep( const TankRender::Direction direction ) const
{
    IColission *colission = m_scene.GetColission();
    assert(colission);

    float step = max_step + 1;
    MovementParams param(GetX(), GetY(), GetWidth(), GetHeight());
    do
    {
        --step;
        if (step < 1)
            break;

        switch (direction)
        {
            case TankRender::Up:
                param.m_y = GetY() - step;
                break;
            case TankRender::Down:
                param.m_y = GetY() + step;
                break;

            case TankRender::Left:
                param.m_x = GetX() - step;
                break;

            case TankRender::Right:
                param.m_x = GetX() + step;
                break;
        }
    }
    while (!colission->CheckMovement(param));
    return step;
 }
