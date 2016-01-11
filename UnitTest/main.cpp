#include <QTest>
#include "Test_IntersectRectangle.h"

int main(int argc, char *argv[])
{
    return QTest::qExec(new Test_IntersectRectangle(), argc, argv);
}
