#ifndef OUTERBOUNDARYSTORE_H
#define OUTERBOUNDARYSTORE_H
#include "MapObjects/OuterBoundary.h"
#include "IOuterBoundaryStore.h"
#include <memory>

class IScene;

class OuterBoundaryStore : public IOuterBoundaryStore
{
public:
    OuterBoundaryStore( const IScene &scene );

    virtual void Init( const RenderParam &param );

    virtual float GetMaxX() const;
    virtual float GetMaxY() const;
    virtual float GetMinX() const;
    virtual float GetMinY() const;

protected:

    float m_maxX;
    float m_maxY;
    float m_minX;
    float m_minY;
    const IScene &m_scene;
};

#endif // OUTERBOUNDARYSTORE_H
