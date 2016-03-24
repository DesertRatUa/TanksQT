#include "SceneObjectsStore.h"

void SceneObjectsStore::Draw()
{
    for ( auto it : m_objects )
    {
        it->Draw();
    }
}

void SceneObjectsStore::Update( const float frameTime )
{
    for ( auto it : m_objects )
    {
        it->Update( frameTime );
    }
    for (auto dit : m_delObjects)
    {
        for ( TObjects::iterator it = m_objects.begin(); it != m_objects.end(); ++it )
        {
            if ( it->get() == dit )
            {
                m_objects.erase(it);
                break;
            }
        }
    }
    m_delObjects.clear();
}

void SceneObjectsStore::Clear()
{
    m_objects.clear();
}

void SceneObjectsStore::Delete( IPlane *obj )
{
    m_delObjects.push_back(obj);
}
