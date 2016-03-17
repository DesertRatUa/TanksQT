#include "TanksStorage.h"
#include "MapObjects/Tank.h"
#include "MapObjectsStore/IOuterBoundaryStore.h"
#include "IScene.h"

TanksStorage::TanksStorage( IScene &scene ) : m_scene(scene)
{
}

void TanksStorage::Init( const RenderParam &param )
{
    m_playerTank.reset( new Tank( param, m_scene ) );

    const IOuterBoundaryStore *outerBoundary = m_scene.GetOuterBoundary();
    m_playerTank->SetX( outerBoundary->GetMaxX() / 2 );
    m_playerTank->SetY( outerBoundary->GetMaxY() / 2 );

    m_objects.push_back( TiPlanePtr( m_playerTank ) );
}

ITank* TanksStorage::GetPlayerTank()
{
    return m_playerTank.get();
}
