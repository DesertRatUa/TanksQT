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

#include "BrickWall.h"
#include "Log.h"

unsigned long BrickWall::m_nextId = 0;

BrickWall::BrickWall( const RenderParam &param ) :
    IBrickWall( param )
{
    m_id = m_nextId++;

    QImage image( ":/Textures/TankSpriteSheet.png" );
    QImage frame = image.copy( 256, 0, 15, 15 );
    frame = frame.mirrored( false, true );
    SetTexture( new QOpenGLTexture( frame) );
    m_name = "BrickWall";

    SetHeight( 50.0f );
    SetWidth( 50.0f );
}

unsigned long BrickWall::GetId() const
{
    return m_id;
}

std::string BrickWall::GetName() const
{
    return Plane::GetName() + Log::IntToStr(GetId());
}
