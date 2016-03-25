#ifndef XBOXCONTROLLERTHREAD_H
#define XBOXCONTROLLERTHREAD_H
#include <QThread>
#include "XBoxControllerEvent.h"

class XBoxControllerThread : public QThread
{
    Q_OBJECT

public:
    XBoxControllerThread();

signals:
    void signalControllerKeyPress( XBoxControllerEvent event );

protected:
    void run();
};

#endif // XBOXCONTROLLERTHREAD_H
