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

#ifndef PLANE_H
#define PLANE_H

#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <vector>
#include <QOpenGLFunctions>
#include "IPlane.h"

typedef std::shared_ptr<QOpenGLTexture> TexturePtr;

struct RenderParam
{
    RenderParam( QOpenGLShaderProgram *program, int vertexAttr, int textureAttr, int textureUniform );

    QOpenGLShaderProgram *m_program;
    int m_vertexAttr;
    int m_textureAttr;
    int m_textureUniform;
};

class Plane : protected QOpenGLFunctions, public IPlane
{
public:
    Plane( const RenderParam &param );
    virtual ~Plane();

    virtual float GetX() const;
    virtual float GetY() const;
    virtual float GetWidth() const;
    virtual float GetHeight() const;
    virtual std::string GetName() const;

    void SetX( const float x );
    void SetY( const float y );
    void SetWidth( const float width );
    void SetHeight( const float GetHeight );

    void SetTexture( QOpenGLTexture *texture );
    void SetTexture( TexturePtr &texture );

    virtual void Draw();

protected:
    void initVertices();
    void initTextureCoords();

    std::vector<float> m_vertices;
    std::vector<float> m_textureCoords;

    TexturePtr m_texture;

    RenderParam m_renderParam;

    float m_x0;
    float m_y0;
    float m_width;
    float m_height;

    std::string m_name;
};



#endif // PLANE_H
