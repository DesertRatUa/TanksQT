#ifndef IPLANE
#define IPLANE

#include "memory"

class IPlane
{
public:
    virtual ~IPlane() {}

    virtual float GetX() const = 0;
    virtual float GetY() const = 0;
    virtual float GetHeight() const = 0;
    virtual float GetWidth() const = 0;
    virtual std::string GetName() const = 0;
};

typedef std::shared_ptr<IPlane> TiPlanePtr;

#endif // IPLANE

