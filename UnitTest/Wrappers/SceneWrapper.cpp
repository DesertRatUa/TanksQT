#include "SceneWrapper.h"
#include <memory>

SceneWrapper::SceneWrapper() :
    m_returnNULL(false),
    m_width(0.f),
    m_height(0.f),
    m_outerBoundaryStore(NULL),
    m_colission(NULL),
    m_tank(NULL),
    m_renderParam(NULL)
{

}

float SceneWrapper::GetWidth() const
{
    if (m_returnNULL)
        return 0.f;
    else
        return m_width;
}

float SceneWrapper::GetHeigth() const
{
    if (m_returnNULL)
        return 0.f;
    else
        return m_height;
}

const IOuterBoundaryStore *SceneWrapper::GetOuterBoundary() const
{
    if (m_returnNULL)
        return NULL;
    else
        return m_outerBoundaryStore;
}

IColission* SceneWrapper::GetColission()
{
    if (m_returnNULL)
        return NULL;
    else
        return m_colission;
}

ITank* SceneWrapper::GetTank()
{
    if (m_returnNULL)
        return NULL;
    else
        return m_tank;
}

RenderParam* SceneWrapper::GetRenderParam()
{
    if (m_returnNULL)
        return NULL;
    else
        return m_renderParam;
}

IProjectileStore* SceneWrapper::GetProjectileStore()
{
    return NULL;
}

void SceneWrapper::Update()
{
}
