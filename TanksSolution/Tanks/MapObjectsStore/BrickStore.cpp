#include "BrickStore.h"
#include "MapObjects/BrickWall.h"
#include "IScene.h"
#include "IColission.h"

BrickStore::BrickStore( IScene &scene ) : m_scene(scene)
{
}

void BrickStore::Init( const RenderParam &param ) throw ( std::runtime_error )
{
    IColission* colission = m_scene.GetColission();
    if (!colission)
        throw std::runtime_error("Colission == NULL");

    BrickWall *wall = new BrickWall( param );
    wall->SetX(110.f);
    wall->SetY(110.f);

    TiPlanePtr wallPtr(wall);
    m_objects.push_back( wallPtr );
    colission->AddColissionObject( wallPtr );
}
