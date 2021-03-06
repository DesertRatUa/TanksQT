#include "EagleStore.h"
#include "IScene.h"
#include "IOuterBoundaryStore.h"
#include "IColission.h"
#include "MapObjects/Eagle.h"

EagleStore::EagleStore( IScene &scene ) :
    m_scene(scene)
{
}

void EagleStore::Init( const RenderParam &param )
{
    const IOuterBoundaryStore *outerBoundary = m_scene.GetOuterBoundary();
    if ( !outerBoundary )
        throw std::runtime_error("OuterBoundaryStore == NULL");

    float middle_x = ( m_scene.GetWidth() - Eagle::GetDefaultWidth() ) / 2;

    AddEagle( "Player", middle_x, outerBoundary->GetMaxY() - Eagle::GetDefaultHeight(), param );
    AddEagle( "Enemy", middle_x, outerBoundary->GetMinY(), param );
}

void EagleStore::AddEagle( const std::string &name, const float x, const float y,
                           const RenderParam &param )
{
    Eagle* eagle = new Eagle( name ,param );
    eagle->SetX( x );
    eagle->SetY( y );
    TiPlanePtr eaglePtr( eagle );
    m_objects.push_back( eaglePtr );
    m_scene.GetColission()->AddColissionObject( eaglePtr );
}
