#ifndef BRICKSTORE_H
#define BRICKSTORE_H
#include "SceneObjectsStore.h"
#include "MapObjects/IBrickWall.h"
class IScene;

class BrickStore : public SceneObjectsStore
{
public:
    BrickStore( IScene &scene );

    virtual void Init( const RenderParam &param ) throw (std::runtime_error);

protected:
    TiBrickWallPtr CreateBrickWall( const RenderParam &param );
    IScene &m_scene;
};

#endif // BRICKSTORE_H
