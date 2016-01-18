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
    virtual void Draw();

    virtual float GetMaxX() const;
    virtual float GetMaxY() const;
    virtual float GetMinX() const;
    virtual float GetMinY() const;

    virtual void Clear();

protected:
    typedef std::shared_ptr<OuterBoundary> TOuterBoundaryPtr;
    typedef std::vector<TOuterBoundaryPtr> TOuterBoundaryVec;
    TOuterBoundaryVec m_outerBoundary;

    float m_maxX;
    float m_maxY;
    float m_minX;
    float m_minY;
    const IScene &m_scene;
};

#endif // OUTERBOUNDARYSTORE_H
