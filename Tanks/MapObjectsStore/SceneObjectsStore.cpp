#include "SceneObjectsStore.h"

SceneObjectsStore::SceneObjectsStore()
{

}

void SceneObjectsStore::Draw()
{
    for ( TObjects::iterator it = m_objects.begin(); it != m_objects.end(); ++it )
    {
        (*it)->Draw();
    }
}

void SceneObjectsStore::Clear()
{
    m_objects.clear();
}
