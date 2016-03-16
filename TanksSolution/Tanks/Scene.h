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
#include "Projectile.h"
#include "ExplosionOfProjectile.h"
#include "ExplosionOfTank.h"
#include "MapObjectsStore//IOuterBoundaryStore.h"
#include "MapObjects/BrickWall.h"
#include "IControlls.h"
#include "IColission.h"
#include "IScene.h"
#include "MapObjectsStore/ISceneObjectsStore.h"


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

    virtual void Update();

private slots:
    void slotOfMovingOfProjectiles();
    void slotShowProjectileExplosion( int id, bool show );
    void slotShowTankExplosion( int id, bool show );

private:
    virtual void CreateDependencys();

    void initializeGL();
    void paintGL();
    void resizeGL( int w, int h );
    void keyPressEvent( QKeyEvent *event );
    void showProjectileExplosions();
    void addProjectileExplosion( float x0, float y0 );
    void addTankExplosion( float x0, float y0 );

    QOpenGLShaderProgram m_program;
    QTimer m_projectileTimer;

    std::unique_ptr<IColission> m_collision;
    std::unique_ptr<IOuterBoundaryStore> m_outerBoundary;
    std::unique_ptr<ITank> m_tank;
    std::unique_ptr<IControlls> m_controls;
    std::unique_ptr<ISceneObjectsStore> m_eagle;
    std::unique_ptr<ISceneObjectsStore> m_brickStore;
    std::unique_ptr<QThread> m_xboxController_thread;

    std::unique_ptr<RenderParam> m_renderParam;

    int m_vertexAttr;
    int m_textureAttr;
    int m_textureUniform;
    int m_matrixUniform;

    float m_scale;
    const float m_canvasHeight;
    const float m_canvasWidth;

    std::map<int, Projectile*> m_projectiles;
    std::map<int, ExplosionOfProjectile*> m_projectileExplosions;
    std::map<int, ExplosionOfTank*> m_tankExplosions;
};

#endif // SCENE_H
