#include <QKeyEvent>
#include <assert.h>

#include "Controlls.h"
#include "MapObjects/ITank.h"
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
            ProcessShoot();
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
 }

 void Controlls::ProcessShoot()
 {
     ITank *tank = m_scene.GetTank();
     assert(tank);

     tank->Shoot();
 }
