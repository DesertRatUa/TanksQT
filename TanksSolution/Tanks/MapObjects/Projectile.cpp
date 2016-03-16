#include "Projectile.h"

Projectile::Projectile( const RenderParam &param ) : IProjectile(param)
{
    QImage image( ":/Textures/TankSpriteSheet.png" );
    QImage frame = image.copy( 21 * 16, 7 * 16, 16, 16 );
    frame = frame.mirrored( false, true );
    m_texture.reset( new QOpenGLTexture( frame) );
    SetTexture( m_texture.get() );
    m_name = "Projectile";

    SetHeight( 50.0f );
    SetWidth( 50.0f );
}
