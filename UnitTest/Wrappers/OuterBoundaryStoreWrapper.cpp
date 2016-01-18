#include "OuterBoundaryStoreWrapper.h"

OuterBoundaryStoreWrapper::OuterBoundaryStoreWrapper() :
    m_maxX(0.f),
    m_maxY(0.f),
    m_minX(0.f),
    m_minY(0.f)
{
}

float OuterBoundaryStoreWrapper::GetMaxX() const
{
    return m_maxX;
}

float OuterBoundaryStoreWrapper::GetMaxY() const
{
    return m_maxY;
}

float OuterBoundaryStoreWrapper::GetMinX() const
{
    return m_minX;
}

float OuterBoundaryStoreWrapper::GetMinY() const
{
    return m_minY;
}
