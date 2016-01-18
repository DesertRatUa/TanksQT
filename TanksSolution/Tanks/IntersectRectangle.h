#ifndef INTERSECTRECTANGLE_H
#define INTERSECTRECTANGLE_H

struct Rectangle
{
public:
    Rectangle();
    Rectangle( const float x1, const float y1, const float x2, const float y2 );
    bool IsIntersect( const Rectangle &rec1 ) const;

    float m_x1;
    float m_x2;
    float m_y1;
    float m_y2;
};

struct IntersectRectangle
{
    static bool IsIntersect( const Rectangle &rec1, const Rectangle &rec2 );
};

#endif // INTERSECTRECTANGLE_H
