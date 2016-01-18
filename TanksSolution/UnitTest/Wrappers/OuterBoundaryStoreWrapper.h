#ifndef OUTERBOUNDARYSTOREWRAPPER_H
#define OUTERBOUNDARYSTOREWRAPPER_H

#include "MapObjectsStore/IOuterBoundaryStore.h"

class OuterBoundaryStoreWrapper : public IOuterBoundaryStore
{
public:
    OuterBoundaryStoreWrapper();

    virtual void Init( const RenderParam &param );
    virtual void Draw();
    virtual void Clear();

    virtual float GetMaxX() const;
    virtual float GetMaxY() const;
    virtual float GetMinX() const;
    virtual float GetMinY() const;

    float m_maxX;
    float m_maxY;
    float m_minX;
    float m_minY;
};

#endif // OUTERBOUNDARYSTOREWRAPPER_H
