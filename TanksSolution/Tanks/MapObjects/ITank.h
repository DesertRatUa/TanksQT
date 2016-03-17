#ifndef ITANK
#define ITANK

#include "TankRender.h"

class ITank : public TankRender
{
public:
    ITank( const RenderParam &param ) : TankRender(param) {}
    virtual ~ITank() {}

    virtual void MoveUp() = 0;
    virtual void MoveDown() = 0;
    virtual void MoveLeft() = 0;
    virtual void MoveRight() = 0;
    virtual void Shoot() = 0;
};

#endif // ITANK

