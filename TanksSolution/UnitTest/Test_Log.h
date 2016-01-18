#ifndef TESTLOG_H
#define TESTLOG_H

#include <QObject>

class Test_Log : public QObject
{
    Q_OBJECT
public:
    explicit Test_Log(QObject *parent = 0);

private slots:
    void TestOutput();
};

#endif // TESTLOG_H
