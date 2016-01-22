#include <assert.h>
#include <algorithm>
#include <QtGlobal>
#include <exception>

#include "Colission.h"
#include "MapObjectsStore/IOuterBoundaryStore.h"
#include "IScene.h"
#include "Log.h"
#include "IntersectRectangle.h"

Colission::Colission( const IScene &scene ) : m_scene(scene)
{
}

bool Colission::CheckMovement( MovementParams &param ) const throw (std::runtime_error)
{
    bool move = CheckOuterBoundary(param);
    bool object = CheckColissionObjects(param);
    return move && object;
}

bool Colission::CheckOuterBoundary( MovementParams &param ) const throw (std::runtime_error)
{
    const IOuterBoundaryStore *boundary = m_scene.GetOuterBoundary();
    if (!boundary)
        throw std::runtime_error("OuterBoundaryStore == NULL");

    bool minx = param.m_x >= boundary->GetMinX();
    bool miny = param.m_y >= boundary->GetMinY();
    bool maxx = param.m_x + param.m_width <= boundary->GetMaxX();
    bool maxy = param.m_y + param.m_height <= boundary->GetMaxY();
    return minx && miny && maxx && maxy;
}

bool Colission::CheckColissionObjects( MovementParams &param ) const
{
    Rectangle obj1( param.m_x, param.m_y,
                    param.m_x + param.m_width, param.m_y + param.m_height );

    for ( TPlanePtrVec::const_iterator it = m_colissionObjects.begin();
          it != m_colissionObjects.end(); ++ it)
    {
        const IPlane &object =  *(*it);

        Rectangle obj2( object.GetX(), object.GetY(),
                        object.GetX() + object.GetWidth(),
                        object.GetY() + object.GetHeight() );

        if ( obj1.IsIntersect(obj2) )
            return false;
    }
    return true;
}

void Colission::AddColissionObject( const TiPlanePtr &plane ) throw (std::runtime_error)
{
    if ( !plane.get() )
        throw std::runtime_error("plane == NULL");

    TPlanePtrVec::iterator it = std::find(
                m_colissionObjects.begin(), m_colissionObjects.end(), plane );

    if (it == m_colissionObjects.end())
    {
        m_colissionObjects.push_back(plane);
        Log::Add( "[Colission] Add colission object: " + plane->GetName() );
    }
    else
    {
        Log::Warning( "[Colission] Item already exist" );
    }
}

void Colission::RemoveColissionObject( const TiPlanePtr &plane ) throw (std::runtime_error)
{
    if ( !plane.get() )
        throw std::runtime_error("plane == NULL");

    TPlanePtrVec::iterator it = std::find(
                m_colissionObjects.begin(), m_colissionObjects.end(), plane );
    if (it != m_colissionObjects.end())
    {
        m_colissionObjects.erase(it);
        Log::Add( "[Colission] Remove colission object: " + plane->GetName() );
    }
    else
        Log::Add( "[Error] Colission object " + plane->GetName() + " not found" );
}

void Colission::Clear()
{
    m_colissionObjects.clear();
    Log::Add( "[Colission] Clear" );
}

unsigned Colission::Size() const
{
    return m_colissionObjects.size();
}
