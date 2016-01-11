#include "IntersectRectangle.h"
#include "Log.h"

Rectangle::Rectangle() : m_x1(0), m_x2(0), m_y1(0), m_y2(0)
{
}

Rectangle::Rectangle( const float x1, const float x2, const float y1, const float y2 ) :
    m_x1(x1), m_x2(x2), m_y1(y1), m_y2(y2)
{
}

bool Rectangle::IsIntersect( const Rectangle &rec1 ) const
{
    return IntersectRectangle::IsIntersect(*this, rec1);
}

bool IntersectRectangle::IsIntersect( const Rectangle &rec1, const Rectangle &rec2 )
{
    /*
    if( rec1.m_left >= rec2.m_right ||
        rec1.m_right <= rec2.m_left ||
        rec1.m_top <= rec2.m_bottom ||
        rec1.m_bottom >= rec2.m_top )
        return false;
    return true;
    */
    bool intersect = rec1.m_x1 < rec2.m_x2 &&
        rec1.m_x2 > rec2.m_x1 &&
        rec1.m_y1 < rec2.m_y2 &&
        rec1.m_y2 > rec2.m_y1;
    return intersect;
}
