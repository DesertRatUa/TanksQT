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
#include "Log.h"

static const float STEP = 10.0f;
static const float FIELD_HEIGHT = 700.0f;
static const float FIELD_WIDTH = 700.0f;
static const unsigned UPDATE_INTERVAL = 10;
static const unsigned FPS_INTERVAL = 1000;


Scene::Scene( QWidget *parent ) :
    QOpenGLWidget( parent ),
    m_scale( 0.5f ),
    m_canvasHeight( FIELD_HEIGHT ),
    m_canvasWidth( FIELD_WIDTH ),
    m_updateInterval( UPDATE_INTERVAL ),
    m_avarageFps( 0 ),
    m_avarageFpsCount( 0 )
{
    CreateDependencys();
    QThreadPool::globalInstance()->setMaxThreadCount( 15 );

    setFocusPolicy( Qt::StrongFocus );

    m_xboxController_thread->start();

    connect(&m_timer, SIGNAL( timeout() ), this, SLOT( slotUpdateLoop() ));
}

Scene::~Scene()
{
    makeCurrent();

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
    m_timer.start(m_updateInterval);
}

void Scene::paintGL()
{
    glEnable( GL_BLEND );

    glClear( GL_COLOR_BUFFER_BIT );

    if ( !m_program.bind() )
        return;

    QMatrix4x4 matrix;
    matrix.ortho( 0.0f, FIELD_HEIGHT, FIELD_WIDTH, 0.0f, -2.0f, 2.0f );
    matrix.scale( m_scale );
    m_program.setUniformValue( m_matrixUniform, matrix );

    m_renderObjectStore->Draw();

    QPainter paint(this);
    paint.setPen(Qt::red);
    paint.setFont(QFont("Arial", 20));
    paint.drawText( 25, 45, Log::IntToStr(m_fps).c_str() );
    paint.drawText( 25, 65, Log::IntToStr(int(m_updateInterval)).c_str() );
    paint.end();
}

void Scene::resizeGL( int w, int h )
{
    glViewport( 0, 0, w, h );
}

void Scene::keyPressEvent( QKeyEvent *event )
{
    m_controls->KeyPress(event);
}

float Scene::GetWidth() const
{
    return FIELD_WIDTH * ( 1 / m_scale );
}

float Scene::GetHeigth() const
{
    return FIELD_HEIGHT * ( 1 / m_scale );
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

float Scene::GetFrameTime()
{
    m_currentFrameTime = std::chrono::system_clock::now();
    std::chrono::duration<float> frame_time( m_currentFrameTime - m_lastFrameTime );
    std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(frame_time);
    m_lastFrameTime = std::chrono::system_clock::now();
    return ms.count();
}

void Scene::slotUpdateLoop()
{
    //m_timer.stop();
    const float frameTime = GetFrameTime();
    UpdateFps(frameTime);

    if (m_renderObjectStore)
        m_renderObjectStore->Update(frameTime);
    update();
    //m_timer.start(m_updateInterval);
}

void Scene::UpdateFps( const float frameTime )
{
    unsigned fps = 1000 / ( frameTime > 0 ? frameTime : 1 );

    if (fps > 60)
        m_updateInterval = 1000 / 60;
    else
        m_updateInterval = UPDATE_INTERVAL;

    m_avarageFps += fps;
    ++m_avarageFpsCount;

    std::chrono::duration<float> fps_time(m_currentFrameTime - m_lastFpsTime);
    std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(fps_time);
    if (ms.count() > FPS_INTERVAL)
    {
        if (m_avarageFpsCount > 0)
        {
            m_fps = m_avarageFps / m_avarageFpsCount;
        }
        else
        {
            m_fps = fps;
        }
        m_lastFpsTime = m_currentFrameTime;
        m_avarageFps = 0;
        m_avarageFpsCount = 0;
    }
}


RenderParam* Scene::GetRenderParam()
{
    return m_renderParam.get();
}

IProjectileStore* Scene::GetProjectileStore()
{
    return m_projectileStore.get();
}
