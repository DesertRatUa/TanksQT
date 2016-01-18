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
    Rectangle rec3( 3.f, 3.f, 7.f, 7.f );
    Rectangle rec4( 6.f, 8.f, 10.f, 15.f );
    Rectangle rec5( 9.f, 5.f, 20.f, 10.f );

    QVERIFY( rec1.IsIntersect(rec3) == true );
    QVERIFY( rec3.IsIntersect(rec1) == true );

    QVERIFY( rec2.IsIntersect(rec3) == true );
    QVERIFY( rec3.IsIntersect(rec2) == true );

    QVERIFY( rec1.IsIntersect(rec4) == true );
    QVERIFY( rec4.IsIntersect(rec1) == true );

    QVERIFY( rec1.IsIntersect(rec5) == true );
    QVERIFY( rec5.IsIntersect(rec1) == true );
}

void Test_IntersectRectangle::TestNoIntersect()
{
    Rectangle rec1( 5.f, 5.f, 10.f, 10.f);
    Rectangle rec2( 0.f, 0.f, 4.f, 4.f);
    Rectangle rec3( 15.f, 15.f, 20.f, 20.f);

    QVERIFY( rec1.IsIntersect(rec2) == false );
    QVERIFY( rec2.IsIntersect(rec1) == false );

    QVERIFY( rec1.IsIntersect(rec3) == false );
    QVERIFY( rec3.IsIntersect(rec1) == false );
}
