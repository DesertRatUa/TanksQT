#include "OuterBoundary.h"

OuterBoundary::OuterBoundary( const RenderParam &param ) :
    Plane( param )
{
    QImage image( ":/Textures/TankSpriteSheet.png" );
    QImage frame = image.copy( 256, 16, 15, 15 );
    frame = frame.mirrored( false, true );
    SetTexture( new QOpenGLTexture( frame ) );

    m_name = "OuterBoundary";
}

OuterBoundary::~OuterBoundary()
{
}
