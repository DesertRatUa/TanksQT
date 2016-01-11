#ifndef ISCENEOBJECTSSTORE
#define ISCENEOBJECTSSTORE

struct RenderParam;

class ISceneObjectsStore
{
public:
    virtual ~ISceneObjectsStore() {}

    virtual void Init( const RenderParam &param ) = 0;
    virtual void Draw() = 0;
    virtual void Clear() = 0;
};

#endif // IEAGLESTORE

