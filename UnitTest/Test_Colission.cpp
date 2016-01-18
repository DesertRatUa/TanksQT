#include <QTest>

#include "Test_Colission.h"
#include "Colission.h"
#include "Wrappers/SceneWrapper.h"
#include "Wrappers/PlaneWrapper.h"

Test_Colission::Test_Colission(QObject *parent) : QObject(parent)
{
}

void Test_Colission::initTestCase()
{
    m_scene.reset( new SceneWrapper() );
    m_colission.reset( new Colission(*m_scene) );
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

void Test_Colission::TestColissionOuterBoundary()
{

}
