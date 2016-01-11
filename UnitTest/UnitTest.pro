QT += testlib
QT -= gui

TARGET = UnitTest
CONFIG += console testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Test_IntersectRectangle.cpp

HEADERS += \
    Test_IntersectRectangle.h

LIBS += Build/debug/IntersectRectangle.o
