#ifndef ISCENEOBJECTSSTORE
#define ISCENEOBJECTSSTORE

#include "memory"

struct RenderParam;
class IPlane;

class ISceneObjectsStore
{
public:
    virtual ~ISceneObjectsStore() {}

    virtual void Init( const RenderParam &param ) = 0;
    virtual void Draw() = 0;
    virtual void Clear() = 0;
    virtual void Update( const float frameTime ) = 0;
    virtual void Delete( IPlane *obj ) = 0;
};

typedef std::shared_ptr<ISceneObjectsStore> TiSceneObjectsStorePtr;

#endif // IEAGLESTORE

