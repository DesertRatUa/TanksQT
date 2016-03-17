#ifndef EAGLE_H
#define EAGLE_H

#include "Plane.h"
#include <memory>

class Eagle : public Plane
{
public:
    Eagle( const std::string &name, const RenderParam &param );
    ~Eagle();

    static float GetDefaultWidth();
    static float GetDefaultHeight();
};

#endif // EAGLE_H
