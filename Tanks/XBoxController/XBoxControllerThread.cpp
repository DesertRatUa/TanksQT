#include "XBoxControllerThread.h"
#include "XBOXController.h"
#include "QKeyEvent"
#include "QApplication"
#include "XBoxControllerEvent.h"

XBoxControllerThread::XBoxControllerThread() :
    m_run(true)
{

}

/*
#define XINPUT_GAMEPAD_DPAD_UP          0x0001
#define XINPUT_GAMEPAD_DPAD_DOWN        0x0002
#define XINPUT_GAMEPAD_DPAD_LEFT        0x0004
#define XINPUT_GAMEPAD_DPAD_RIGHT       0x0008
*/

void XBoxControllerThread::run()
{
    CXBOXController controller(1);
    while (m_run)
    {
        QApplication::processEvents();
        if(controller.IsConnected())
        {
            WORD buttns = controller.GetState().Gamepad.wButtons;
            if( buttns & XINPUT_GAMEPAD_A)
            {
                emit signalControllerKeyPress(XBB_A);
            }

            if( buttns & XINPUT_GAMEPAD_B)
            {
                 emit signalControllerKeyPress(XBB_B);
            }

            if( buttns & XINPUT_GAMEPAD_X)
            {
                 emit signalControllerKeyPress(XBB_X);
            }

            if  ( buttns & XINPUT_GAMEPAD_Y)
            {
                 emit signalControllerKeyPress(XBB_Y);
            }

            if( buttns & XINPUT_GAMEPAD_DPAD_UP)
            {
                emit signalControllerKeyPress(XBB_DP_U);
            }

            if( buttns & XINPUT_GAMEPAD_DPAD_DOWN)
            {
                 emit signalControllerKeyPress(XBB_DP_D);
            }

            if( buttns & XINPUT_GAMEPAD_DPAD_LEFT)
            {
                 emit signalControllerKeyPress(XBB_DP_L);
            }

            if  ( buttns & XINPUT_GAMEPAD_DPAD_RIGHT)
            {
                 emit signalControllerKeyPress(XBB_DP_R);
            }
        }
        msleep(100);
    }
}

