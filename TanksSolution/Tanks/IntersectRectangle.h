#ifndef INTERSECTRECTANGLE_H
#define INTERSECTRECTANGLE_H

struct Rectangle
{
public:
    Rectangle();
    Rectangle( const float left, const float right, const float top, const float buttom );
    bool IsIntersect( const Rectangle &rec1 ) const;

    float m_left;
    float m_right;
    float m_top;
    float m_bottom;
};

struct IntersectRectangle
{
    static bool IsIntersect( const Rectangle &rec1, const Rectangle &rec2 );
};

#endif // INTERSECTRECTANGLE_H
