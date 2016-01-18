#include "PlaneWrapper.h"

PlaneWrapper::PlaneWrapper() :
    m_x(0.f),
    m_y(0.f),
    m_height(0.f),
    m_width(0.f)
{
}

float PlaneWrapper::GetX() const
{
    return m_x;
}

float PlaneWrapper::GetY() const
{
    return m_y;
}

float PlaneWrapper::GetHeight() const
{
    return m_height;
}

float PlaneWrapper::GetWidth() const
{
    return m_width;
}

std::string PlaneWrapper::GetName() const
{
    return m_name;
}
