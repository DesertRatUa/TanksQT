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
    QVERIFY( m_colission->Size() == 0 );
}

void Test_Colission::TestAddObject()
{
    m_colission->Clear();
    QVERIFY( m_colission->Size() == 0 );

    TiPlanePtr obj1(new PlaneWrapper);
    TiPlanePtr obj2(new PlaneWrapper);

    m_colission->AddColissionObject(obj1);
    QVERIFY( m_colission->Size() == 1 );

    m_colission->AddColissionObject(obj2);
    QVERIFY( m_colission->Size() == 2 );
}

void Test_Colission::TestRemoveObject()
{
    m_colission->Clear();
    QVERIFY( m_colission->Size() == 0 );

    TiPlanePtr obj1(new PlaneWrapper);
    TiPlanePtr obj2(new PlaneWrapper);


}
