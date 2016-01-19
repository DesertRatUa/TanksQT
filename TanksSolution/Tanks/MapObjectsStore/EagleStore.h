#ifndef EAGLESTORE_H
#define EAGLESTORE_H

#include <memory>

#include "SceneObjectsStore.h"

class IScene;
class EagleStore : public SceneObjectsStore
{
public:
    EagleStore( IScene &scene );

    virtual void Init( const RenderParam &param );

protected:
    void AddEagle( const std::string &name, const float x, const float y , const RenderParam &param);

    IScene &m_scene;
};

#endif // EAGLESTORE_H
