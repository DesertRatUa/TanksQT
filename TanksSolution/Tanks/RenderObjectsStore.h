#ifndef RENDEROBJECTSSTORE_H
#define RENDEROBJECTSSTORE_H

#include <memory>
#include <vector>

#include "IRenderObjectsStore.h"

class ISceneObjectsStore;
class RenderParam;

class RenderObjectsStore : public IRenderObjectsStore
{
public:
    virtual ~RenderObjectsStore() {}

    virtual void AddStorage( TiSceneObjectsStorePtr storage );
    virtual void Init( const RenderParam &param );
    virtual void Clear();
    virtual void Draw();
    virtual void Update( const float frameTime );

protected:
    typedef std::vector<TiSceneObjectsStorePtr> RenderObjects;
    RenderObjects m_renderObjects;
};

#endif // RENDEROBJECTSSTORE_H
