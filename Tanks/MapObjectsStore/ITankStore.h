#ifndef ITANKSTORE_H
#define ITANKSTORE_H

#include "SceneObjectsStore.h"

class ITank;

class ITankStorage : public SceneObjectsStore
{
public:
    virtual ~ITankStorage() {}

    virtual ITank* GetPlayerTank() = 0;
};

#endif // TANKSSTORAGE_H
