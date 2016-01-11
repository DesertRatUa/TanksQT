#include "IntersectRectangle.h"
#include "Log.h"

Rectangle::Rectangle() : m_left(0), m_right(0), m_top(0), m_bottom(0)
{
}

Rectangle::Rectangle( const float left, const float right, const float top, const float buttom ) :
    m_left(left), m_right(right), m_top(top), m_bottom(buttom)
{
}

bool Rectangle::IsIntersect( const Rectangle &rec1 ) const
{
    return IntersectRectangle::IsIntersect(*this, rec1);
}

bool IntersectRectangle::IsIntersect( const Rectangle &rec1, const Rectangle &rec2 )
{
    if( rec1.m_left >= rec2.m_right ||
        rec1.m_right <= rec2.m_left ||
        rec1.m_top <= rec2.m_bottom ||
        rec1.m_bottom >= rec2.m_top )
        return false;
    return true;
}
