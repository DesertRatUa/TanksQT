#include <string>
#include <QTest>

#include "Test_Log.h"
#include "Log.h"

Test_Log::Test_Log(QObject *parent) : QObject(parent)
{
}

void Test_Log::TestOutput()
{
    qDebug("UnitTest Print TEST");
    qDebug("===================");

    std::string text("[TestLog] output text");

    Log::Init("");

    Log::Add(text);
    Log::Warning(text);
    Log::Error(text);

    Log::Close();

    qDebug("===================");
}
