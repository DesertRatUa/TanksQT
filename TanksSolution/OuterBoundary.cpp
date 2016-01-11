#include "OuterBoundary.h"

const float height = 50.0f;
const float width = 50.0f;

OuterBoundary::OuterBoundary( const RenderParam &param ) :
    Plane( param )
{
    QImage image( ":/Textures/TankSpriteSheet.png" );
    QImage frame = image.copy( 256, 16, 15, 15 );
    frame = frame.mirrored( false, true );
    m_texture.reset( new QOpenGLTexture( frame ) );
    SetTexture( m_texture.get() );

    SetHeight( height );
    SetWidth( width );
}

OuterBoundary::~OuterBoundary()
{
    if (m_texture.get())
        m_texture->destroy();
}

float OuterBoundary::GetDefaultWidth()
{
    return width;
}

float OuterBoundary::GetDefaultHeight()
{
    return height;
}
