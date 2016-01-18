#include <QTest>

#include "Test_Colission.h"
#include "Colission.h"
#include "Wrappers/SceneWrapper.h"
#include "Wrappers/PlaneWrapper.h"
#include "Wrappers/OuterBoundaryStoreWrapper.h"

Test_Colission::Test_Colission(QObject *parent) : QObject(parent)
{
}

void Test_Colission::initTestCase()
{
    m_colission.reset( new Colission(m_scene) );

    m_scene.m_outerBoundaryStore = &m_outerBoundary;

    m_outerBoundary.m_maxX = 100.f;
    m_outerBoundary.m_maxY = 100.f;
}

void Test_Colission::cleanup()
{
    m_colission->Clear();
    QCOMPARE( m_colission->Size(), unsigned(0) );
}

void Test_Colission::TestAddObject()
{
    TiPlanePtr obj1(new PlaneWrapper);
    TiPlanePtr obj2(new PlaneWrapper);

    m_colission->AddColissionObject(obj1);
    QCOMPARE( m_colission->Size(), unsigned(1) );

    m_colission->AddColissionObject(obj1);
    QCOMPARE( m_colission->Size(), unsigned(1) );

    m_colission->AddColissionObject(obj2);
    QCOMPARE( m_colission->Size(), unsigned(2) );

    m_colission->AddColissionObject(obj2);
    QCOMPARE( m_colission->Size(), unsigned(2) );
}

void Test_Colission::TestRemoveObject()
{
    TiPlanePtr obj1(new PlaneWrapper);
    TiPlanePtr obj2(new PlaneWrapper);

    m_colission->AddColissionObject(obj1);
    m_colission->AddColissionObject(obj2);

    m_colission->RemoveColissionObject( obj1 );
    QCOMPARE( m_colission->Size(), unsigned(1) );

    m_colission->RemoveColissionObject( obj1 );
    QCOMPARE( m_colission->Size(), unsigned(1) );

    m_colission->RemoveColissionObject( obj2 );
    QCOMPARE( m_colission->Size(), unsigned(0) );

    m_colission->RemoveColissionObject( obj2 );
    QCOMPARE( m_colission->Size(), unsigned(0) );
}

void Test_Colission::TestOuterBoundaryDeny()
{
    MovementParams up( 50.f, -10.f, 10.f, 10.f );
    QVERIFY( m_colission->CheckMovement(up) == false );

    MovementParams down( 50.f, 105.f, 10.f, 10.f );
    QVERIFY( m_colission->CheckMovement(down) == false );

    MovementParams down1( 50.f, 95.f, 10.f, 10.f );
    QVERIFY( m_colission->CheckMovement(down1) == false );

    MovementParams left( -5.f, 50.f, 10.f, 10.f );
    QVERIFY( m_colission->CheckMovement(left) == false );

    MovementParams right( 95.f, 50.f, 10.f, 10.f );
    QVERIFY( m_colission->CheckMovement(right) == false );

    MovementParams right1( 105.f, 50.f, 10.f, 10.f );
    QVERIFY( m_colission->CheckMovement(right1) == false );
}

void Test_Colission::TestOuterBoundaryAllow()
{
    MovementParams center( 50.f, 50.f, 10.f, 10.f );
    QVERIFY( m_colission->CheckMovement(center) == true );

    MovementParams up( 50.f, 0.f, 10.f, 10.f );
    QVERIFY( m_colission->CheckMovement(up) == true );

    MovementParams left( 0.f, 50.f, 10.f, 10.f );
    QVERIFY( m_colission->CheckMovement(left) == true );

    MovementParams right( 90.f, 50.f, 10.f, 10.f );
    QVERIFY( m_colission->CheckMovement(right) == true );

    MovementParams down( 50.f, 90.f, 10.f, 10.f );
    QVERIFY( m_colission->CheckMovement(down) == true );
}

void Test_Colission::TestMapObjectsDeny()
{
    PlaneWrapper *obj1 = new PlaneWrapper();
    obj1->m_x = 50.f;
    obj1->m_y = 50.f;
    obj1->m_height = 20.f;
    obj1->m_width = 20.f;

    TiPlanePtr obj(obj1);

    m_colission->AddColissionObject(obj);

    MovementParams inside( 55.f, 55.f, 10.f, 10.f );
    QVERIFY( m_colission->CheckMovement(inside) == false );

    MovementParams center( 50.f, 50.f, 20.f, 20.f );
    QVERIFY( m_colission->CheckMovement(center) == false );

    MovementParams up( 50.f, 70.f, 10.f, 10.f );
    QVERIFY( m_colission->CheckMovement(up) == false );

    MovementParams down( 50.f, 40.f, 10.f, 10.f );
    QVERIFY( m_colission->CheckMovement(up) == false );

    MovementParams left( 70.f, 50.f, 10.f, 10.f );
    QVERIFY( m_colission->CheckMovement(left) == false );

    MovementParams right( 40.f, 50.f, 10.f, 10.f );
    QVERIFY( m_colission->CheckMovement(right) == false );
}

void Test_Colission::TestMapObjectsAllow()
{
    PlaneWrapper *obj1 = new PlaneWrapper();
    obj1->m_x = 50.f;
    obj1->m_y = 50.f;
    obj1->m_height = 20.f;
    obj1->m_width = 20.f;

    TiPlanePtr obj(obj1);

    m_colission->AddColissionObject(obj);

    MovementParams side( 25.f, 25.f, 20.f, 20.f );
    QVERIFY( m_colission->CheckMovement(side) == true );

    MovementParams up( 50.f, 71.f, 10.f, 10.f );
    QVERIFY( m_colission->CheckMovement(up) == true );

    MovementParams down( 50.f, 39.f, 10.f, 10.f );
    QVERIFY( m_colission->CheckMovement(up) == true );

    MovementParams left( 71.f, 50.f, 10.f, 10.f );
    QVERIFY( m_colission->CheckMovement(left) == true );

    MovementParams right( 39.f, 50.f, 10.f, 10.f );
    QVERIFY( m_colission->CheckMovement(right) == true );
}

void Test_Colission::TestNull()
{
    m_scene.m_outerBoundaryStore = NULL;

    MovementParams inside( 55.f, 55.f, 10.f, 10.f );
    QEXPECT_FAIL("","NULL Warriable",Continue);
    QTRY_VERIFY( m_colission->CheckMovement(inside) == false );

}
