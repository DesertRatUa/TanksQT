#ifndef OUTERBOUNDARY_H
#define OUTERBOUNDARY_H

#include "Plane.h"
#include <memory>

class OuterBoundary : public Plane
{
public:
    OuterBoundary( const RenderParam &param );
    ~OuterBoundary();

    static float GetDefaultWidth();
    static float GetDefaultHeight();

protected:
    std::shared_ptr<QOpenGLTexture> m_texture;
};

#endif // OUTERBOUNDARY_H
