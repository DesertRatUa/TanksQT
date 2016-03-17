#ifndef CONTROLLS_H
#define CONTROLLS_H
#include <QObject>
#include "IControlls.h"

class QKeyEvent;
class ITank;
class IScene;

class Controlls : public IControlls
{
public:
    Controlls( IScene &scene );

    virtual void KeyPress( QKeyEvent *event );

public slots:
    virtual void slotControllerKeyPress( XBoxControllerEvent key );

protected:
    enum Movement
    {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        NONE,
    };

    void ProcessMovement(const Movement move);
    void ProcessShoot();

    IScene &m_scene;
};

#endif // CONTROLLS_H
