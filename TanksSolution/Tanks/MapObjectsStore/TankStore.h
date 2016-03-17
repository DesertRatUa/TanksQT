#ifndef TANKSTORE_H
#define TANKSTORE_H

#include "ITankStore.h"

class IScene;
class ITank;

class TankStore : public ITankStorage
{
public:
    TankStore( IScene &scene );

    virtual void Init( const RenderParam &param );
    virtual ITank* GetPlayerTank();
    virtual void Clear();

protected:
    typedef std::shared_ptr<ITank> TiTankPtr;

    TiTankPtr m_playerTank;
    IScene &m_scene;
};

#endif // TANKSSTORAGE_H
