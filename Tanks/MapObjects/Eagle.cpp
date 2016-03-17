#include "Eagle.h"
#include <QImage>

static float WIDTH = 50.0f;
static float HEIGHT = 50.0f;

Eagle::Eagle( const std::string &name , const RenderParam &param ) :
    Plane( param )
{
    QImage image( ":/Textures/TankSpriteSheet.png" );
    QImage frame = image.copy( 304, 32, 15, 15 );
    frame = frame.mirrored( false, true );
    SetTexture( new QOpenGLTexture( frame ) );

    SetHeight( HEIGHT );
    SetWidth( WIDTH );

    m_name = "Eagle: " + name;
}

Eagle::~Eagle()
{
}

float Eagle::GetDefaultWidth()
{
    return WIDTH;
}

float Eagle::GetDefaultHeight()
{
    return HEIGHT;
}
