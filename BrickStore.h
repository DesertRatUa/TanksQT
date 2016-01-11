#ifndef BRICKSTORE_H
#define BRICKSTORE_H
#include "ISceneObjectsStore.h"

class IScene;

class BrickStore : public ISceneObjectsStore
{
public:
    BrickStore( IScene &scene );

    virtual void Init( const RenderParam &param );
    virtual void Draw();
    virtual void Clear();

protected:
    IScene &m_scene;
};

#endif // BRICKSTORE_H
