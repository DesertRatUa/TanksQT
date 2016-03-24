#include <stdlib.h>
#include <QTimer>

#include "Projectile.h"
#include "IScene.h"
#include "IColission.h"
#include "MapObjectsStore/IProjectileStore.h"

static const float SPEED = 0.4f;

Projectile::Projectile(const Direction direction, const RenderParam &param, IScene &scene ) :
    IProjectile(param), m_scene(scene), m_direction(direction)
{
    QImage image( ":/Textures/TankSpriteSheet.png" );
    QImage frame = image.copy( 21 * 16, 7 * 16, 16, 16 );
    frame = frame.mirrored( false, true );
    SetTexture( new QOpenGLTexture( frame) );
    m_name = "Projectile";
}

void Projectile::Update( const float frameTime )
{
    MovementParams param(GetX(), GetY(), GetWidth(), GetHeight());
    const float distance = SPEED * frameTime;

    switch (m_direction)
    {
        case Up:
            param.m_y = GetY() - distance;
            break;
        case Down:
            param.m_y = GetY() + distance;
            break;

        case Left:
            param.m_x = GetX() - distance;
            break;

        case Right:
            param.m_x = GetX() + distance;
            break;
    }
    if (m_scene.GetColission()->CheckMovement( param ))
    {
        SetX( param.m_x );
        SetY( param.m_y );
    }
    else
    {
        m_scene.GetProjectileStore()->Delete(this);
    }
}
