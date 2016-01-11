#ifndef ICONTROLLS
#define ICONTROLLS
#include "XBoxController/XBoxControllerEvent.h"
#include "QObject"

class QKeyEvent;

class IControlls : public QObject
{
    Q_OBJECT

public:
    virtual ~IControlls() {}

    virtual void KeyPress( QKeyEvent *event ) = 0;

public slots:
    virtual void slotControllerKeyPress( XBoxControllerEvent key ) = 0;

};

#endif // IEAGLESTORE

