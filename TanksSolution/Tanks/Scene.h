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

#ifndef SCENE_H
#define SCENE_H

#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <QKeyEvent>
#include <QTimer>
#include <map>
#include <QOpenGLFunctions>
#include "MapObjects/ITank.h"
#include "Ice.h"
#include "MapObjects/BrickWall.h"
#include "IControlls.h"
#include "IColission.h"
#include "IScene.h"
#include "IRenderObjectsStore.h"
#include "MapObjectsStore/IOuterBoundaryStore.h"
#include "MapObjectsStore/ITankStore.h"
#include "MapObjectsStore/IProjectileStore.h"

class Scene : public QOpenGLWidget, protected QOpenGLFunctions, public IScene
{
    Q_OBJECT

public:
    Scene( QWidget *parent = 0 );
    ~Scene();

    virtual float GetWidth() const;
    virtual float GetHeigth() const;
    virtual const IOuterBoundaryStore* GetOuterBoundary() const;
    virtual IColission* GetColission();
    virtual ITank* GetTank();
    virtual RenderParam* GetRenderParam();
    virtual IProjectileStore* GetProjectileStore();

    virtual void Update();

public slots:
    void slotUpdateLoop();

private:
    virtual void CreateDependencys();

    void initializeGL();
    void paintGL();
    void resizeGL( int w, int h );
    void keyPressEvent( QKeyEvent *event );

    QOpenGLShaderProgram m_program;
    QTimer m_timer;

    std::unique_ptr<IColission> m_collision;
    std::unique_ptr<IControlls> m_controls;
    std::unique_ptr<QThread> m_xboxController_thread;
    std::unique_ptr<IRenderObjectsStore> m_renderObjectStore;
    std::unique_ptr<RenderParam> m_renderParam;

    std::shared_ptr<IOuterBoundaryStore> m_outerBoundary;
    std::shared_ptr<ITankStorage> m_tankStore;
    std::shared_ptr<IProjectileStore> m_projectileStore;

    int m_vertexAttr;
    int m_textureAttr;
    int m_textureUniform;
    int m_matrixUniform;

    float m_scale;
    const float m_canvasHeight;
    const float m_canvasWidth;
    const unsigned m_updateInterval;
};

#endif // SCENE_H
