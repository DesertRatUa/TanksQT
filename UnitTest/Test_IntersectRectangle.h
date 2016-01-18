#ifndef TEST_INTERSECTRECTANGLE_H
#define TEST_INTERSECTRECTANGLE_H
#include <QObject>

class Test_IntersectRectangle : public QObject
{
    Q_OBJECT

public:
    Test_IntersectRectangle();

private slots:
    void TestIntersect();
    void TestNoIntersect();
};

#endif // TEST_INTERSECTRECTANGLE_H
