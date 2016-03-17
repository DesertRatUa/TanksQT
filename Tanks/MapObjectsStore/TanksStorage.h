#ifndef TANKSSTORAGE_H
#define TANKSSTORAGE_H

#include "ITanksStorage.h"

class IScene;
class ITank;

class TanksStorage : public ITanksStorage
{
public:
    TanksStorage( IScene &scene );

    virtual void Init( const RenderParam &param );
    virtual ITank* GetPlayerTank();

protected:
    typedef std::shared_ptr<ITank> TiTankPtr;

    TiTankPtr m_playerTank;
    IScene &m_scene;
};

#endif // TANKSSTORAGE_H
