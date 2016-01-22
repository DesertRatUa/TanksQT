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

    for ( unsigned i = 0; i < 20; ++i )
    {
        TiBrickWallPtr wall = CreateBrickWall( param );
        wall->SetX(110.f + i * wall->GetWidth());
        wall->SetY(210.f);

        m_objects.push_back( wall );
        colission->AddColissionObject( wall );
    }

    for ( unsigned i = 1; i < 20; ++i )
    {
        TiBrickWallPtr wall = CreateBrickWall( param );
        wall->SetX(110.f );
        wall->SetY(210.f + i * wall->GetHeight());

        m_objects.push_back( wall );
        colission->AddColissionObject( wall );
    }

    for ( unsigned i = 1; i < 9; ++i )
    {
        TiBrickWallPtr wall = CreateBrickWall( param );
        wall->SetX(110.f + wall->GetHeight() * 5 );
        wall->SetY(210.f + i * wall->GetHeight());

        m_objects.push_back( wall );
        colission->AddColissionObject( wall );
    }

    for ( unsigned i = 11; i < 20; ++i )
    {
        TiBrickWallPtr wall = CreateBrickWall( param );
        wall->SetX(110.f + wall->GetHeight() * 5 );
        wall->SetY(210.f + i * wall->GetHeight());

        m_objects.push_back( wall );
        colission->AddColissionObject( wall );
    }

    for ( unsigned i = 0; i < 20; ++i )
    {
        TiBrickWallPtr wall = CreateBrickWall( param );
        wall->SetX(110.f + i * wall->GetWidth());
        wall->SetY(210.f + 19 * wall->GetHeight());

        m_objects.push_back( wall );
        colission->AddColissionObject( wall );
    }
}

TiBrickWallPtr BrickStore::CreateBrickWall( const RenderParam &param )
{
    return TiBrickWallPtr( new BrickWall( param ) );
}
