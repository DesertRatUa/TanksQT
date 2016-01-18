#include "Test_Colission.h"
#include "Colission.h"
#include "SceneWrapper.h"

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
    m_colission->clear();
}

void Test_Colission::TestAddObject()
{

}
