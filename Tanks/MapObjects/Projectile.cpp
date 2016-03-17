#include <stdlib.h>
#include <QTimer>

#include "Projectile.h"
#include "IScene.h"

static Projectile *m_proj = NULL;

Projectile::Projectile( const RenderParam &param, IScene &scene ) :
    IProjectile(param), m_scene(scene)
{
    QImage image( ":/Textures/TankSpriteSheet.png" );
    QImage frame = image.copy( 21 * 16, 7 * 16, 16, 16 );
    frame = frame.mirrored( false, true );
    SetTexture( new QOpenGLTexture( frame) );
    m_name = "Projectile";

    SetHeight( 50.0f );
    SetWidth( 50.0f );
    m_proj = this;

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL( timeout() ), this, SLOT( slotTimerUpdate() ));
    timer->start(200);
}

void Projectile::slotTimerUpdate()
{
    m_proj->SetX(m_proj->GetX() + ( ( std::rand() % 20 ) - 10) );
    m_proj->SetY(m_proj->GetY() + ( ( std::rand() % 20 ) - 10) );
    m_scene.Update();
}
