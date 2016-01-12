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
    Plane.cpp \
    Projectile.cpp \
    SoundOfShot.cpp \
    SoundOfTankExplosion.cpp \
    SoundOfProjectileExplosion.cpp \
    ExplosionOfProjectile.cpp \
    ExplosionOfTank.cpp \
    OuterBoundary.cpp \
    Eagle.cpp \
    Controlls.cpp \
    TankRender.cpp \
    Tank.cpp \
    Colission.cpp \
    OuterBoundaryStore.cpp \
    EagleStore.cpp \
    Log.cpp \
    IntersectRectangle.cpp \
    XBoxController/XBoxControllerThread.cpp \
    XBoxController/XBoxController.cpp \
    BrickStore.cpp \
    BrickWall.cpp

HEADERS  += Dialog.h \
    Scene.h \
    Ice.h \
    Plane.h \
    Projectile.h \
    SoundOfShot.h \
    SoundOfTankExplosion.h \
    SoundOfProjectileExplosion.h \
    ExplosionOfProjectile.h \
    ExplosionOfTank.h \
    OuterBoundary.h \
    Eagle.h \
    Controlls.h \
    TankRender.h \
    Tank.h \
    ITank.h \
    Colission.h \
    IColission.h \
    OuterBoundaryStore.h \
    IOuterBoundaryStore.h \
    IScene.h \
    EagleStore.h \
    IPlane.h \
    Log.h \
    IntersectRectangle.h \
    XBoxController/XBoxControllerThread.h \
    XBoxController/XBoxController.h \
    XBoxController/XBoxControllerEvent.h \
    BrickStore.h \
    IControlls.h \
    ISceneObjectsStore.h \
    BrickWall.h

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
