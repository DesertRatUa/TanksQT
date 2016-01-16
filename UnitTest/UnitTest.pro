QT += testlib
QT -= gui

TARGET = UnitTest
CONFIG += console testcase c++11
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Test_IntersectRectangle.cpp \
    Test_Colission.cpp \
    SceneWrapper.cpp

HEADERS += \
    Test_IntersectRectangle.h \
    Test_Colission.h \
    SceneWrapper.h

LIBS += $$PWD/../Build/Tanks/debug/IntersectRectangle.o $$PWD/../Build/Tanks/debug/Colission.o $$PWD/../Build/Tanks/debug/Log.o

INCLUDEPATH += $$PWD/../Tanks
