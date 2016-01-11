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

#ifndef BLOCKOFBRICKWALL_H
#define BLOCKOFBRICKWALL_H

#include "Plane.h"
#include <memory>

class BlockOfBrickWall : public Plane
{
public:
    BlockOfBrickWall( const RenderParam &param );
    ~BlockOfBrickWall();

    int id() const;

protected:
    std::shared_ptr<QOpenGLTexture> m_texture;


    int m_health;
    int m_id;
    static int m_nextId;
};

#endif // BLOCKOFBRICKWALL_H
