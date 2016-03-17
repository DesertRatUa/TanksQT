#include "OuterBoundary.h"

const float height = 50.0f;
const float width = 50.0f;

OuterBoundary::OuterBoundary( const RenderParam &param ) :
    Plane( param )
{
    QImage image( ":/Textures/TankSpriteSheet.png" );
    QImage frame = image.copy( 256, 16, 15, 15 );
    frame = frame.mirrored( false, true );
    SetTexture( new QOpenGLTexture( frame ) );

    SetHeight( height );
    SetWidth( width );

    m_name = "OuterBoundary";
}

OuterBoundary::~OuterBoundary()
{
}

float OuterBoundary::GetDefaultWidth()
{
    return width;
}

float OuterBoundary::GetDefaultHeight()
{
    return height;
}
