#ifndef OUTERBOUNDARY_H
#define OUTERBOUNDARY_H

#include "Plane.h"
#include <memory>

class OuterBoundary : public Plane
{
public:
    OuterBoundary( const RenderParam &param );
    ~OuterBoundary();
};

#endif // OUTERBOUNDARY_H
