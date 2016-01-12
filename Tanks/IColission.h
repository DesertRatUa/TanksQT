#ifndef ICOLISSION
#define ICOLISSION

#include "MapObjects/IPlane.h"

struct MovementParams
{
    MovementParams(float x, float y, float width, float height) : m_x(x), m_y(y), m_width(width), m_height(height) {}
    float m_x;
    float m_y;
    float m_width;
    float m_height;
};

class IColission
{
public:
    virtual ~IColission() {}

    virtual bool CheckMovement(MovementParams &param) const = 0;

    virtual void AddColissionObject( const TiPlanePtr &plane ) = 0;
    virtual void RemoveColissionObject( const TiPlanePtr &plane ) = 0;

    virtual void Clear() = 0;
};

#endif // ICOLISSION
