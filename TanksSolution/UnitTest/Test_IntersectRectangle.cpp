#include <QTest>

#include "Test_IntersectRectangle.h"
#include "IntersectRectangle.h"

Test_IntersectRectangle::Test_IntersectRectangle()
{

}

void Test_IntersectRectangle::TestIntersect()
{
    Rectangle rec1( 5.f, 5.f, 10.f, 10.f);
    Rectangle rec2( 0.f, 0.f, 4.f, 4.f);
    Rectangle rec3( 4.f, 4.f, 7.f, 7.f );

    //QVERIFY2( rec1.IsIntersect(rec2) == false, "No intersect" );
    //QVERIFY2( rec1.IsIntersect(rec3) == true, "Intersect" );
    //QVERIFY2( rec2.IsIntersect(rec3) == true, "Intersect" );

}
