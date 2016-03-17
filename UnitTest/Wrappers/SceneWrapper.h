#ifndef SCENEWRAPPER_H
#define SCENEWRAPPER_H

#include "IScene.h"

class SceneWrapper : public IScene
{
public:
    SceneWrapper();

    virtual float GetWidth() const;
    virtual float GetHeigth() const ;
    virtual const IOuterBoundaryStore *GetOuterBoundary() const;
    virtual IColission* GetColission();
    virtual ITank* GetTank();
    virtual RenderParam* GetRenderParam();
    virtual IProjectileStore* GetProjectileStore();

    virtual void Update();

    bool m_returnNULL;

    float m_width;
    float m_height;

    IOuterBoundaryStore * m_outerBoundaryStore;
    IColission* m_colission;
    ITank* m_tank;
    RenderParam* m_renderParam;
};

#endif // SCENEWRAPPER_H
