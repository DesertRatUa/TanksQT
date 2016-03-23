#include "Eagle.h"
#include <QImage>

Eagle::Eagle( const std::string &name , const RenderParam &param ) :
    Plane( param )
{
    QImage image( ":/Textures/TankSpriteSheet.png" );
    QImage frame = image.copy( 304, 32, 15, 15 );
    frame = frame.mirrored( false, true );
    SetTexture( new QOpenGLTexture( frame ) );

    m_name = "Eagle: " + name;
}

Eagle::~Eagle()
{
}
