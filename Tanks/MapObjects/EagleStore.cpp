#include "EagleStore.h"
#include "IScene.h"
#include "IOuterBoundaryStore.h"
#include "IColission.h"

EagleStore::EagleStore( IScene &scene ) :
    m_scene(scene)
{
}

void EagleStore::Init( const RenderParam &param )
{
    const IOuterBoundaryStore *outerBoundary = m_scene.GetOuterBoundary();

    float middle_x = ( m_scene.GetWidth() - Eagle::GetDefaultWidth() ) / 2;

    AddEagle( "Player", middle_x, outerBoundary->GetMaxY() - Eagle::GetDefaultHeight(), param );
    AddEagle( "Enemy", middle_x, outerBoundary->GetMinY(), param );
}

void EagleStore::AddEagle( const std::string &name, const float x, const float y,
                           const RenderParam &param )
{
    TEaglePtr eagle( new Eagle( name ,param ) );
    eagle->SetX( x );
    eagle->SetY( y );
    m_eagles.push_back(eagle);
    m_scene.GetColission()->AddColissionObject(eagle);
}

void EagleStore::Draw()
{
    for ( TEagleVec::iterator it = m_eagles.begin(); it != m_eagles.end(); ++it )
        (*it)->Draw();
}

void EagleStore::Clear()
{
    m_eagles.clear();
}
