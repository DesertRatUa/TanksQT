#ifndef MAPOBJECTSSTORE_H
#define MAPOBJECTSSTORE_H

#include <vector>

#include "ISceneObjectsStore.h"
#include "MapObjects/IPlane.h"

class SceneObjectsStore : public ISceneObjectsStore
{
public:
    virtual ~SceneObjectsStore() {}

    virtual void Init( const RenderParam &param ) = 0;
    virtual void Draw();
    virtual void Clear();
    virtual void Update( const float frameTime );
    virtual void Delete( IPlane *obj );

protected:
    typedef std::vector<TiPlanePtr> TObjects;
    typedef std::vector<IPlane*> TPtrObjects;
    TObjects m_objects;
    TPtrObjects m_delObjects;
};

#endif // MAPOBJECTSSTORE_H
