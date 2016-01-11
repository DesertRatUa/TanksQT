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

#include "Projectile.h"

int Projectile::m_nextId = 0;

Projectile::Projectile( RenderParam &param ) :
    Plane( param )
{
    m_id = m_nextId++;

    QImage image( ":/Textures/TankSpriteSheet.png" );

    QImage frame = image.copy( 323, 102, 4, 4 );
    m_upTexture = new QOpenGLTexture( frame );

    frame = image.copy( 330, 102, 4, 4 );
    m_rightTexture = new QOpenGLTexture( frame );

    frame = image.copy( 339, 102, 4, 4 );
    m_downTexture = new QOpenGLTexture( frame );

    frame = image.copy( 346, 102, 4, 3 );
    m_leftTexture = new QOpenGLTexture( frame );

    setDirection( Projectile::Left );
}

Projectile::~Projectile()
{
    m_downTexture->destroy();
    delete m_downTexture;
    m_rightTexture->destroy();
    delete m_rightTexture;
    m_upTexture->destroy();
    delete m_upTexture;
    m_leftTexture->destroy();
    delete m_leftTexture;
}

Projectile::Direction Projectile::direction() const
{
    return m_direction;
}

void Projectile::setDirection( Projectile::Direction direction )
{
    m_direction = direction;

    switch( m_direction )
    {
        case Projectile::Down:
            SetTexture( m_downTexture );
            break;
        case Projectile::Right:
            SetTexture( m_rightTexture );
            break;
        case Projectile::Up:
            SetTexture( m_upTexture );
            break;
        case Projectile::Left:
            SetTexture( m_leftTexture );
            break;
    }
}

int Projectile::id() const
{
    return m_id;
}

