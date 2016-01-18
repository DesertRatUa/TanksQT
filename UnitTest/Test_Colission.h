#ifndef TEST_COLISSION_H
#define TEST_COLISSION_H

#include <QObject>
#include <memory>

#include "IColission.h"
#include "IScene.h"

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

private:
    std::unique_ptr<IColission> m_colission;
    std::unique_ptr<IScene> m_scene;
};

#endif // TEST_COLISSION_H
