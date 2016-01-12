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
    m_texture.reset( new QOpenGLTexture( frame ) );
    SetTexture( m_texture.get() );

    SetHeight( HEIGHT );
    SetWidth( WIDTH );

    m_name = "Eagle: " + name;
}

Eagle::~Eagle()
{
    if (m_texture.get())
        m_texture->destroy();
}

float Eagle::GetDefaultWidth()
{
    return WIDTH;
}

float Eagle::GetDefaultHeight()
{
    return HEIGHT;
}
