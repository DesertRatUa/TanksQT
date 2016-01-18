#ifndef EAGLESTORE_H
#define EAGLESTORE_H
#include "ISceneObjectsStore.h"
#include "MapObjects/Eagle.h"
#include "memory"

class IScene;
class EagleStore : public ISceneObjectsStore
{
public:
    EagleStore( IScene &scene );

    virtual void Init( const RenderParam &param );
    virtual void Draw();
    virtual void Clear();

protected:
    void AddEagle( const std::string &name, const float x, const float y , const RenderParam &param);

    typedef std::shared_ptr<Eagle> TEaglePtr;
    typedef std::vector<TEaglePtr> TEagleVec;
    TEagleVec m_eagles;
    IScene &m_scene;
};

#endif // EAGLESTORE_H
