/*
    The Game Tanks

    Copyright (C) 2014  Enzhaev Ivan

    Email: 8observer8@gmail.com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "Tank.h"

TankRender::TankRender( const RenderParam &param ) :
    Plane( param ),
    m_isReloading( false )
{
    genTextures();
    SetDirection( TankRender::Up );

    SetHeight( 50.0f );
    SetWidth( 50.0f );
}

TankRender::~TankRender()
{
    SetTexture(NULL);
    for ( size_t i = 0; i < m_upTextures.size(); ++i )
    {
        DestroyTexture(m_upTextures[i]);
    }

    for ( size_t i = 0; i < m_downTextures.size(); ++i )
    {
         DestroyTexture(m_downTextures[i]);
    }

    for ( size_t i = 0; i < m_rightTextures.size(); ++i )
    {
        DestroyTexture(m_rightTextures[i]);
    }

    for ( size_t i = 0; i < m_leftTextures.size(); ++i )
    {
        DestroyTexture(m_leftTextures[i]);
    }
}

void TankRender::genTextures()
{
    QImage image( ":/Textures/TankSpriteSheet.png" );

    int frameHeight = image.height() / 16;
    int frameWidth = image.width() / 25;

    std::vector<QImage> frames;
    for ( int i = 0; i < 8; ++i )
    {
        unsigned x = i * frameWidth;
        unsigned y = 0;
        unsigned width = frameWidth;
        unsigned height = frameHeight;

        QImage frame = image.copy( x, y, width, height );
        qDebug("%u, %u, %u, %u", x, y, width, height );
        //QMatrix matrix;
        //matrix.rotate( 180.0 );
        //frame = frame.transformed( matrix );
        //frame = frame.mirrored( true, false );
        frame = frame.scaledToHeight(frameHeight);
        frame = frame.scaledToWidth(frameWidth);
        frames.push_back( frame );
    }

    m_upTextures.push_back( new QOpenGLTexture( frames[4] ) );
    m_upTextures.push_back( new QOpenGLTexture( frames[5] ) );

    m_leftTextures.push_back( new QOpenGLTexture( frames[2] ) );
    m_leftTextures.push_back( new QOpenGLTexture( frames[3] ) );

    m_downTextures.push_back( new QOpenGLTexture( frames[0] ) );
    m_downTextures.push_back( new QOpenGLTexture( frames[1] ) );

    m_rightTextures.push_back( new QOpenGLTexture( frames[6] ) );
    m_rightTextures.push_back( new QOpenGLTexture( frames[7] ) );
}

void TankRender::DestroyTexture(QOpenGLTexture* texture)
{
    if (texture)
        texture->destroy();
    delete texture;
}

void TankRender::SetDirection( TankRender::Direction dir )
{
    m_direction = dir;

    switch( m_direction )
    {
        case TankRender::Up:
            SetTexture( m_upTextures[0] );
            break;
        case TankRender::Left:
            SetTexture( m_leftTextures[0] );
            break;
        case TankRender::Down:
            SetTexture( m_downTextures[0] );
            break;
        case TankRender::Right:
            SetTexture( m_rightTextures[0] );
            break;
    }
    NextFrame();
}

void TankRender::NextFrame()
{
    static unsigned int counter = 0;

    switch( m_direction )
    {
        case TankRender::Up:
            SetTexture( m_upTextures[counter] );
            break;
        case TankRender::Left:
            SetTexture( m_leftTextures[counter] );
            break;
        case TankRender::Down:
            SetTexture( m_downTextures[counter] );
            break;
        case TankRender::Right:
            SetTexture( m_rightTextures[counter] );
            break;
    }

    ++counter;

    if ( counter >= 2 )
        counter = 0;
}

void TankRender::shot()
{
    connect( &m_timerOfReloading, SIGNAL( timeout() ),
             this, SLOT( slotStopReloading() ) );
    m_timerOfReloading.start( 500 );
    m_isReloading = true;
}

bool TankRender::isReloading() const
{
    return m_isReloading;
}

void TankRender::slotStopReloading()
{
    m_timerOfReloading.stop();
    m_isReloading = false;
}
