#ifndef IRENDEROBJECTSSTORE_H
#define IRENDEROBJECTSSTORE_H

#include "MapObjectsStore/ISceneObjectsStore.h"

class RenderParam;

class IRenderObjectsStore
{
public:
    virtual ~IRenderObjectsStore() {}

    virtual void AddStorage( TiSceneObjectsStorePtr storage ) = 0;
    virtual void Init( const RenderParam &param ) = 0;
    virtual void Clear() = 0;
    virtual void Draw() = 0;
};

#endif // RENDEROBJECTSSTORE_H
