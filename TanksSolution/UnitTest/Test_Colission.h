#ifndef TEST_COLISSION_H
#define TEST_COLISSION_H

#include <QObject>
#include <memory>

#include "IColission.h"
#include "Wrappers/SceneWrapper.h"
#include "Wrappers/OuterBoundaryStoreWrapper.h"

class Test_Colission : public QObject
{
    Q_OBJECT
public:
    explicit Test_Colission(QObject *parent = 0);

private slots:
    void initTestCase();
    void cleanup();

    void TestAddObject();
    void TestRemoveObject();
    void TestOuterBoundaryDeny();
    void TestOuterBoundaryAllow();
    void TestMapObjectsDeny();
    void TestMapObjectsAllow();
    void TestNull();

private:
    std::unique_ptr<IColission> m_colission;

    OuterBoundaryStoreWrapper m_outerBoundary;
    SceneWrapper m_scene;
};

#endif // TEST_COLISSION_H
