#ifndef EAGLE_H
#define EAGLE_H

#include "Plane.h"
#include <memory>

class Eagle : public Plane
{
public:
    Eagle( const std::string &name, const RenderParam &param );
    ~Eagle();
};

#endif // EAGLE_H
