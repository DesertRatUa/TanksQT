#ifndef MAPOBJECTSSTORE_H
#define MAPOBJECTSSTORE_H

#include <vector>

#include "ISceneObjectsStore.h"
#include "MapObjects/IPlane.h"

class SceneObjectsStore : public ISceneObjectsStore
{
public:
    SceneObjectsStore();

    virtual void Init( const RenderParam &param ) = 0;
    virtual void Draw();
    virtual void Clear();

protected:
    typedef std::vector<TiPlanePtr> TObjects;
    TObjects m_objects;
};

#endif // MAPOBJECTSSTORE_H
