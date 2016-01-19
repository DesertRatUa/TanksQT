#ifndef IOUTERBOUNDARYSTORE
#define IOUTERBOUNDARYSTORE
#include "SceneObjectsStore.h"

class IOuterBoundaryStore : public SceneObjectsStore
{
public:
    virtual ~IOuterBoundaryStore() {}

    virtual float GetMaxX() const = 0;
    virtual float GetMaxY() const = 0;
    virtual float GetMinX() const = 0;
    virtual float GetMinY() const = 0;
};

#endif // IOUTERBOUNDARYSTORE

