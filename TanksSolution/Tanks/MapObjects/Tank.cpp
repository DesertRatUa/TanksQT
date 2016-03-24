#include <assert.h>

#include "Tank.h"
#include "IScene.h"
#include "IColission.h"
#include "MapObjectsStore/IOuterBoundaryStore.h"
#include "MapObjectsStore/IProjectileStore.h"

static const float max_step = 10.0f;

Tank::Tank( const RenderParam &param, IScene &scene ) :
    ITank(param), m_scene( scene )
{
    m_name = "Tank";
}

void Tank::MoveUp()
{
    float step = CalculateStep( Up );
    if (step > 0)
        SetY( GetY() - step );
    SetDirection( Up );
    m_scene.Update();
}

void Tank::MoveDown()
{
    float step = CalculateStep( Down );
    if (step > 0)
        SetY( GetY() + step );
    SetDirection( Down );
    m_scene.Update();
}

void Tank::MoveLeft()
{
    float step = CalculateStep( Left );
    if ( step > 0 )
        SetX( GetX() - step );
    SetDirection( Left );
    m_scene.Update();
}

void Tank::MoveRight()
{
    float step = CalculateStep( Right );
    if ( step > 0 )
        SetX( GetX() + step );
    SetDirection( Right );
    m_scene.Update();
}

float Tank::CalculateStep( const Direction direction ) const
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
            case Up:
                param.m_y = GetY() - step;
                break;
            case Down:
                param.m_y = GetY() + step;
                break;

            case Left:
                param.m_x = GetX() - step;
                break;

            case Right:
                param.m_x = GetX() + step;
                break;
        }
    }
    while (!colission->CheckMovement(param));
    return step;
 }

void Tank::Shoot()
{
    IProjectileStore *store = m_scene.GetProjectileStore();
    float x = 0.f;
    float y = 0.f;

    switch (GetDirection())
    {
        case Up:
            x = GetX();
            y = GetY() - store->GetDefaultHeight();
            break;
        case Down:
            x = GetX();
            y = GetY() + GetHeight();
            break;

        case Left:
            x = GetX() - store->GetDefaultWidth();
            y = GetY();
            break;

        case Right:
            x = GetX() + GetWidth();
            y = GetY();
            break;
    }
    store->CreateProjectile( GetDirection(), x, y);
}
