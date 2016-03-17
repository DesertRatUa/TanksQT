#ifndef ITANKSSTORAGE_H
#define ITANKSSTORAGE_H

#include "SceneObjectsStore.h"

class ITank;

class ITanksStorage : public SceneObjectsStore
{
public:
    virtual ITank* GetPlayerTank() = 0;
};

#endif // TANKSSTORAGE_H
