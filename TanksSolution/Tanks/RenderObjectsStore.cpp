#include "RenderObjectsStore.h"
#include "MapObjectsStore/ISceneObjectsStore.h"

void RenderObjectsStore::AddStorage( TiSceneObjectsStorePtr storage )
{
    m_renderObjects.push_back(storage);
}

void RenderObjectsStore::Init( const RenderParam &param )
{
    for ( auto it: m_renderObjects )
    {
        it->Init(param);
    }
}

void RenderObjectsStore::Clear()
{
    for ( auto it: m_renderObjects )
    {
        it->Clear();
    }
}

void RenderObjectsStore::Draw()
{
    for ( auto it: m_renderObjects )
    {
        it->Draw();
    }
}

void RenderObjectsStore::Update( const float frameTime )
{
    for ( auto it: m_renderObjects )
    {
        it->Update( frameTime );
    }
}
