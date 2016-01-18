#-------------------------------------------------
#
# Project created by QtCreator 2014-12-28T13:08:35
#
#-------------------------------------------------

QT       += core gui opengl widgets

CONFIG += c++11

#QMAKE_LFLAGS += -static -static-libgcc

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tanks
TEMPLATE = app


SOURCES += main.cpp\
        Dialog.cpp \
    Scene.cpp \
    Ice.cpp \
    MapObjects/Plane.cpp \
    Projectile.cpp \
    SoundOfShot.cpp \
    SoundOfTankExplosion.cpp \
    SoundOfProjectileExplosion.cpp \
    ExplosionOfProjectile.cpp \
    ExplosionOfTank.cpp \
    MapObjects/OuterBoundary.cpp \
    MapObjects/Eagle.cpp \
    Controlls.cpp \
    MapObjects/TankRender.cpp \
    MapObjects/Tank.cpp \
    Colission.cpp \
    MapObjects/OuterBoundaryStore.cpp \
    MapObjects/EagleStore.cpp \
    Log.cpp \
    IntersectRectangle.cpp \
    XBoxController/XBoxControllerThread.cpp \
    XBoxController/XBoxController.cpp \
    MapObjects/BrickStore.cpp \
    MapObjects/BrickWall.cpp

HEADERS  += Dialog.h \
    Scene.h \
    Ice.h \
    MapObjects/Plane.h \
    Projectile.h \
    SoundOfShot.h \
    SoundOfTankExplosion.h \
    SoundOfProjectileExplosion.h \
    ExplosionOfProjectile.h \
    ExplosionOfTank.h \
    MapObjects/OuterBoundary.h \
    MapObjects/Eagle.h \
    Controlls.h \
    MapObjects/TankRender.h \
    MapObjects/Tank.h \
    MapObjects/ITank.h \
    Colission.h \
    IColission.h \
    MapObjects/OuterBoundaryStore.h \
    MapObjects/IOuterBoundaryStore.h \
    IScene.h \
    MapObjects/EagleStore.h \
    MapObjects/IPlane.h \
    Log.h \
    IntersectRectangle.h \
    XBoxController/XBoxControllerThread.h \
    XBoxController/XBoxController.h \
    XBoxController/XBoxControllerEvent.h \
    MapObjects/BrickStore.h \
    IControlls.h \
    MapObjects/ISceneObjectsStore.h \
    MapObjects/BrickWall.h

FORMS    += Dialog.ui

RESOURCES += \
    Shaders.qrc \
    Textures.qrc \
    Sounds.qrc

QMAKE_CFLAGS_DEBUG -= -O
QMAKE_CFLAGS_DEBUG -= -O1
QMAKE_CFLAGS_DEBUG -= -O2
QMAKE_CFLAGS_DEBUG -= -O3


LIBS += C:/Windows/system32/XInput1_3.dll