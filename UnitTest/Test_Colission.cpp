#include <QTest>

#include "Test_Colission.h"
#include "Colission.h"
#include "Wrappers/SceneWrapper.h"

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

}
