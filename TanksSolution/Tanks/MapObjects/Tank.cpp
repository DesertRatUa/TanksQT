#include <assert.h>

#include "Tank.h"
#include "IScene.h"
#include "IColission.h"
#include "MapObjectsStore/IOuterBoundaryStore.h"

static const float max_step = 10.0f;

Tank::Tank( IScene &scene ) :
    m_scene( scene )
{
}

void Tank::Init( RenderParam &param )
{
    m_render.reset( new TankRender( param ) );

    m_render->SetHeight( 50.0f );
    m_render->SetWidth( 50.0f );

    const IOuterBoundaryStore *outerBoundary = m_scene.GetOuterBoundary();
    m_render->SetX( outerBoundary->GetMaxX() / 2 );
    m_render->SetY( outerBoundary->GetMaxY() / 2 );
}

void Tank::Draw()
{
   if ( m_render.get() )
    m_render->Draw();
}

void Tank::MoveUp()
{
    float step = CalculateStep( TankRender::Up );
    if (step > 0)
        m_render->SetY( m_render->GetY() - step );
    m_render->SetDirection( TankRender::Up );
}

void Tank::MoveDown()
{
    float step = CalculateStep( TankRender::Down );
    if (step > 0)
        m_render->SetY( m_render->GetY() + step );
    m_render->SetDirection( TankRender::Down );
}

void Tank::MoveLeft()
{
    float step = CalculateStep( TankRender::Left );
    if ( step > 0 )
        m_render->SetX( m_render->GetX() - step );
    m_render->SetDirection( TankRender::Left );
}

void Tank::MoveRight()
{
    float step = CalculateStep( TankRender::Right );
    if ( step > 0 )
        m_render->SetX( m_render->GetX() + step );
    m_render->SetDirection( TankRender::Right );
}

float Tank::CalculateStep( const TankRender::Direction direction ) const
{
    IColission *colission = m_scene.GetColission();
    assert(colission);

    float step = max_step + 1;
    MovementParams param(m_render->GetX(), m_render->GetY(), m_render->GetWidth(), m_render->GetHeight());
    do
    {
        --step;
        if (step < 1)
            break;

        switch (direction)
        {
            case TankRender::Up:
                param.m_y = m_render->GetY() - step;
                break;
            case TankRender::Down:
                param.m_y = m_render->GetY() + step;
                break;

            case TankRender::Left:
                param.m_x = m_render->GetX() - step;
                break;

            case TankRender::Right:
                param.m_x = m_render->GetX() + step;
                break;
        }
    }
    while (!colission->CheckMovement(param));
    return step;
 }
