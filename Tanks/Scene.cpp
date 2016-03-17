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

#include <QMatrix4x4>
#include <QThreadPool>
#include <QGLWidget>
#include <assert.h>

#include "Scene.h"
#include "SoundOfShot.h"
#include "SoundOfProjectileExplosion.h"
#include "XBoxController/XBoxControllerThread.h"
#include "Colission.h"
#include "Controlls.h"
#include "RenderObjectsStore.h"
#include "MapObjectsStore/BrickStore.h"
#include "MapObjectsStore/ProjectileStore.h"
#include "MapObjectsStore/TankStore.h"
#include "MapObjectsStore/EagleStore.h"
#include "MapObjectsStore/OuterBoundaryStore.h"

static const float step = 10.0f;
static const float field_height = 700.0f;
static const float field_width = 700.0f;

Scene::Scene( QWidget *parent ) :
    QOpenGLWidget( parent ),
    m_scale( 0.5f ),
    m_canvasHeight( 700.0f ),
    m_canvasWidth( 700.0f )
{
    CreateDependencys();
    QThreadPool::globalInstance()->setMaxThreadCount( 15 );

    setFocusPolicy( Qt::StrongFocus );

    m_xboxController_thread->start();
}

Scene::~Scene()
{
    makeCurrent();

    for ( auto it = m_projectileExplosions.begin(); it != m_projectileExplosions.end(); ++it )
        delete it->second;

    for ( auto it = m_tankExplosions.begin(); it != m_tankExplosions.end(); ++it )
        delete it->second;

    m_collision->Clear();
    m_renderObjectStore->Clear();

    doneCurrent();
}

void Scene::CreateDependencys()
{
    m_collision.reset( new Colission( *this ) );
    m_outerBoundary.reset( new OuterBoundaryStore( *this ) );
    m_controls.reset( new Controlls( *this ) );
    m_xboxController_thread.reset( new XBoxControllerThread() ); 
    m_tankStore.reset( new TankStore( *this ) );
    m_renderObjectStore.reset( new RenderObjectsStore() );

    TiSceneObjectsStorePtr eagleStore( new EagleStore( *this) );
    TiSceneObjectsStorePtr brickStore( new BrickStore(*this) );
    m_projectileStore.reset( new ProjectileStore(*this) );

    m_renderObjectStore->AddStorage( m_outerBoundary );
    m_renderObjectStore->AddStorage( brickStore );
    m_renderObjectStore->AddStorage( eagleStore );
    m_renderObjectStore->AddStorage( m_tankStore );
    m_renderObjectStore->AddStorage( m_projectileStore );

    qRegisterMetaType<XBoxControllerEvent>("XBoxControllerEvent");
    connect( m_xboxController_thread.get(), SIGNAL( signalControllerKeyPress( XBoxControllerEvent ) ),
             m_controls.get(), SLOT( slotControllerKeyPress( XBoxControllerEvent ) ) );
}

void Scene::initializeGL()
{
    initializeOpenGLFunctions();

    glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );

    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    glEnable( GL_BLEND );

    QOpenGLShader vShader( QOpenGLShader::Vertex );
    vShader.compileSourceFile( ":/Shaders/vShader.glsl" );

    QOpenGLShader fShader( QOpenGLShader::Fragment );
    fShader.compileSourceFile( ":/Shaders/fShader.glsl" );

    m_program.addShader( &vShader );
    m_program.addShader( &fShader );
    if ( !m_program.link() )
    {
        qWarning( "Error: unable to link a shader program." );
        return;
    }

    m_vertexAttr = m_program.attributeLocation( "vertexAttr" );
    m_textureAttr = m_program.attributeLocation( "textureAttr" );
    m_textureUniform = m_program.uniformLocation( "textureUniform" );
    m_matrixUniform = m_program.uniformLocation( "matrix" );

    m_renderParam.reset( new RenderParam( &m_program, m_vertexAttr, m_textureAttr, m_textureUniform ));

    m_renderObjectStore->Init( *m_renderParam );
}

void Scene::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT );

    if ( !m_program.bind() )
        return;

    QMatrix4x4 matrix;
    matrix.ortho( 0.0f, field_height, field_width, 0.0f, -2.0f, 2.0f );
    matrix.scale( m_scale );
    m_program.setUniformValue( m_matrixUniform, matrix );

    m_renderObjectStore->Draw();
}

void Scene::resizeGL( int w, int h )
{
    glViewport( 0, 0, w, h );
}

void Scene::keyPressEvent( QKeyEvent *event )
{
    m_controls->KeyPress(event);
}

void Scene::addProjectileExplosion( float x0, float y0 )
{
    ExplosionOfProjectile *explosion = new ExplosionOfProjectile( RenderParam( &m_program, m_vertexAttr, m_textureAttr, m_textureUniform ) );
    explosion->SetX( x0 );
    explosion->SetY( y0 );
    connect( explosion, SIGNAL( signalShowProjectileExplosion( int, bool ) ),
             this, SLOT( slotShowProjectileExplosion( int, bool ) ) );
    m_projectileExplosions[explosion->id()] = explosion;
    explosion->start();

    update();
}

void Scene::addTankExplosion( float x0, float y0 )
{
    ExplosionOfTank *explosion = new ExplosionOfTank( RenderParam( &m_program, m_vertexAttr, m_textureAttr, m_textureUniform ) );
    explosion->SetX( x0 );
    explosion->SetY( y0 );
    connect( explosion, SIGNAL( signalShowTankExplosion( int, bool ) ),
             this, SLOT( slotShowTankExplosion( int, bool ) ) );
    m_tankExplosions[explosion->id()] = explosion;
    explosion->start();

    update();
}

void Scene::slotShowProjectileExplosion( int id, bool show )
{
    auto it = m_projectileExplosions.find( id );

    if ( show == false )
    {
        delete it->second;
        m_projectileExplosions.erase( it );
    }

    update();
}

void Scene::slotShowTankExplosion( int id, bool show )
{
    auto it = m_tankExplosions.find( id );

    if ( show == false )
    {
        delete it->second;
        m_tankExplosions.erase( it );
    }

    update();
}

float Scene::GetWidth() const
{
    return field_width * ( 1 / m_scale );
}

float Scene::GetHeigth() const
{
    return field_height * ( 1 / m_scale );
}

const IOuterBoundaryStore *Scene::GetOuterBoundary() const
{
    return m_outerBoundary.get();
}

IColission* Scene::GetColission()
{
    return m_collision.get();
}

ITank* Scene::GetTank()
{
    return m_tankStore->GetPlayerTank();
}

void Scene::Update()
{
    update();
}

RenderParam* Scene::GetRenderParam()
{
    return m_renderParam.get();
}

IProjectileStore* Scene::GetProjectileStore()
{
    return m_projectileStore.get();
}
