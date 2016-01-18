QT += testlib
QT -= gui

TARGET = UnitTest
CONFIG += console testcase c++11
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Test_IntersectRectangle.cpp \
    Test_Colission.cpp \
    SceneWrapper.cpp \
    PlaneWrapper.cpp

HEADERS += \
    Test_IntersectRectangle.h \
    Test_Colission.h \
    SceneWrapper.h \
    PlaneWrapper.h

LIBS += $$PWD/../Build/Tanks/debug/IntersectRectangle.o $$PWD/../Build/Tanks/debug/Colission.o $$PWD/../Build/Tanks/debug/Log.o

INCLUDEPATH += $$PWD/../Tanks

QMAKE_CFLAGS_DEBUG -= -O
QMAKE_CFLAGS_DEBUG -= -O1
QMAKE_CFLAGS_DEBUG -= -O2
QMAKE_CFLAGS_DEBUG -= -O3
