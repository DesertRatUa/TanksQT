#include <QTest>

#include "Test_IntersectRectangle.h"
#include "../Tanks/IntersectRectangle.h"

Test_IntersectRectangle::Test_IntersectRectangle()
{

}

void Test_IntersectRectangle::TestIntersect()
{
    Rectangle rec1( 2.f, 2.f, 4.f, 4.f);
    Rectangle rec2( 1.f, 1.f, 2.f, 2.f);

    QVERIFY2( rec1.IsIntersect(rec2) == false, "No intersect" );
}
