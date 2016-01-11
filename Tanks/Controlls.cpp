#include "Controlls.h"
#include <QKeyEvent>
#include <assert.h>
#include "ITank.h"
#include "IScene.h"

Controlls::Controlls( IScene &scene ) : m_scene(scene)
{
}

void Controlls::KeyPress( QKeyEvent *event )
{
    switch( event->key() )
    {
        case Qt::Key_Up:
        case Qt::Key_W:
            ProcessMovement(UP);
            break;
        case Qt::Key_Left:
        case Qt::Key_A:
            ProcessMovement(LEFT);
            break;
        case Qt::Key_Right:
        case Qt::Key_D:
            ProcessMovement(RIGHT);
            break;
        case Qt::Key_Down:
        case Qt::Key_S:
            ProcessMovement(DOWN);
            break;
        case Qt::Key_Space:
            /*
            if ( !m_tank->isReloading() )
            {
                m_tank->shot();

                Projectile *projectile = new Projectile( &m_program, m_vertexAttr, m_textureAttr, m_textureUniform );
                projectile->setHeight( 8.0f );
                projectile->setWidth( 8.0f );

                float x0, y0;

                switch( m_tank->direction() )
                {
                    case Tank::Up:
                        x0 = m_tank->x0() + m_tank->width() / 2.0f - projectile->width() / 2.0f - 2.0f;
                        y0 = m_tank->y0() - projectile->height() + projectile->height() / 2.0f;
                        projectile->setDirection( Projectile::Up );
                        break;
                    case Tank::Left:
                        x0 = m_tank->x0() - projectile->width() + projectile->width() / 2.0f;
                        y0 = m_tank->y0() + m_tank->height() / 2.0f - projectile->height() / 2.0f - 1.0f;
                        projectile->setDirection( Projectile::Left );
                        break;
                    case Tank::Down:
                        x0 = m_tank->x0() + m_tank->width() / 2.0f - 4.0f;
                        y0 = m_tank->y0() + m_tank->height() - projectile->height() / 2.0f;
                        projectile->setDirection( Projectile::Down );
                        break;
                    case Tank::Right:
                        x0 = m_tank->x0() + m_tank->width() - projectile->width() / 2.0f;
                        y0 = m_tank->y0() + m_tank->height() / 2.0f - projectile->height() / 2.0f - 2.0f;
                        projectile->setDirection( Projectile::Right );
                        break;
                }

                projectile->setX0( x0 );
                projectile->setY0( y0 );
                m_projectileTimer.start( 20 );
                m_projectiles[projectile->id()] = projectile;

//                SoundOfShot *sound = new SoundOfShot;
//                sound->setAutoDelete( true );
//                QThreadPool::globalInstance()->start( sound );
            }

//            if ( m_projectile == 0 )
//            {
//                m_projectile = new Projectile( &m_program, m_vertexAttr, m_textureAttr, m_textureUniform );
//                float x0, y0;

//                switch( m_tank->direction() )
//                {
//                    case Tank::Up:
//                        x0 = m_tank->x0();
//                        y0 = m_tank->y0() - m_projectile->height();
//                        m_projectile->setDirection( Projectile::Up );
//                        break;
//                    case Tank::Left:
//                        x0 = m_tank->x0() - m_projectile->width();
//                        y0 = m_tank->y0();
//                        m_projectile->setDirection( Projectile::Left );
//                        break;
//                    case Tank::Down:
//                        x0 = m_tank->x0();
//                        y0 = m_tank->y0() + m_projectile->height();
//                        m_projectile->setDirection( Projectile::Down );
//                        break;
//                    case Tank::Right:
//                        x0 = m_tank->x0() + m_tank->width();
//                        y0 = m_tank->y0();
//                        m_projectile->setDirection( Projectile::Right );
//                        break;
//                }

//                m_projectile->setX0( x0 );
//                m_projectile->setY0( y0 );

//                m_projectileTimer.start( 5 );

//                // Add timer for reloading

//                SoundOfShot *sound = new SoundOfShot;
//                sound->setAutoDelete( true );
//                QThreadPool::globalInstance()->start( sound );

//                m_effect = new QSoundEffect;
//                m_effect->setSource( QUrl::fromLocalFile( ":/Sounds/Explosion.wav" ) );
                //effect.setLoopCount( QSoundEffect::Infinite) ;
//                m_effect->setVolume( 0.3f );
//                m_effect->play();
//            }
            */
            break;
    }
}

void Controlls::slotControllerKeyPress(XBoxControllerEvent key)
{    
    switch (key)
    {
    case XBB_DP_D:
        ProcessMovement(DOWN);
        break;
    case XBB_DP_L:
        ProcessMovement(LEFT);
        break;
    case XBB_DP_R:
        ProcessMovement(RIGHT);
        break;
    case XBB_DP_U:
        ProcessMovement(UP);
        break;
    default:
        break;
    }
}

 void Controlls::ProcessMovement(const Movement move)
 {
     ITank *tank = m_scene.GetTank();
     assert(tank);

     switch (move)
     {
     case UP:
         tank->MoveUp();
         break;
     case LEFT:
         tank->MoveLeft();
         break;
     case RIGHT:
         tank->MoveRight();
         break;
     case DOWN:
         tank->MoveDown();
         break;
     default:
         return;
     }

     m_scene.Update();
 }
