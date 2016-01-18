#include "OuterBoundaryStore.h"
#include "IScene.h"

OuterBoundaryStore::OuterBoundaryStore( const IScene &scene ) :
    m_maxX(0.0f),
    m_maxY(0.0f),
    m_minX(0.0f),
    m_minY(0.0f),
    m_scene(scene)
{
}

void OuterBoundaryStore::Init( const RenderParam &param )
{
    m_minX = OuterBoundary::GetDefaultWidth();
    m_minY = OuterBoundary::GetDefaultHeight();
    m_maxX = m_scene.GetWidth() - m_minX;
    m_maxY = m_scene.GetHeigth() - m_minY;

    unsigned count_hor = m_scene.GetWidth() / m_minX;
    unsigned count_ver = m_scene.GetHeigth() / m_minY - 1;

    const float top_y = 0.0f;
    const float left_x = 0.0f;

    // Top
    for ( unsigned int i = 0, j = 0; i < count_hor; ++i )
    {
        TOuterBoundaryPtr outerBoundary(new OuterBoundary( param ));
        outerBoundary->SetX( j++ * m_minX );
        outerBoundary->SetY( top_y );
        m_outerBoundary.push_back( outerBoundary );
    }

    //Bottom

    for ( unsigned int i = 0, j = 0; i < count_hor; ++i )
    {
        TOuterBoundaryPtr outerBoundary(new OuterBoundary( param ));
        outerBoundary->SetX( j++ * m_minX );
        outerBoundary->SetY( m_maxY );
        m_outerBoundary.push_back( outerBoundary );
    }

    // Left
    for ( unsigned int i = 1, j = 1; i < count_ver; ++i )
    {
        TOuterBoundaryPtr outerBoundary(new OuterBoundary( param ));
        outerBoundary->SetX( left_x );
        outerBoundary->SetY( j++ * m_minY );
        m_outerBoundary.push_back( outerBoundary );
    }

    // Right
    for ( unsigned int i = 1, j = 1; i < count_ver; ++i )
    {
        TOuterBoundaryPtr outerBoundary(new OuterBoundary( param ));
        outerBoundary->SetX( m_maxX );
        outerBoundary->SetY( j++ * m_minY );
        m_outerBoundary.push_back( outerBoundary );
    }
}

void OuterBoundaryStore::Draw()
{
    for ( TOuterBoundaryVec::iterator it = m_outerBoundary.begin(); it != m_outerBoundary.end(); ++it )
        (*it)->Draw();
}

float OuterBoundaryStore::GetMaxX() const
{
    return m_maxX;
}

float OuterBoundaryStore::GetMaxY() const
{
    return m_maxY;
}

float OuterBoundaryStore::GetMinX() const
{
    return m_minX;
}

float OuterBoundaryStore::GetMinY() const
{
    return m_minY;
}

void OuterBoundaryStore::Clear()
{
    m_outerBoundary.clear();
}
