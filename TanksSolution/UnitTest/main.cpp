#include <QTest>
#include "Test_IntersectRectangle.h"
#include "Test_Colission.h"
#include "Test_Log.h"

int main(int argc, char *argv[])
{
    return QTest::qExec(new Test_IntersectRectangle(), argc, argv) |
            QTest::qExec(new Test_Colission(), argc, argv) |
            QTest::qExec(new Test_Log(), argc, argv);
}
