#ifndef ISCENE
#define ISCENE

class IOuterBoundaryStore;
class IColission;
class ITank;
class IProjectileStore;
struct RenderParam;

class IScene
{
public:
    virtual ~IScene() {}

    virtual float GetWidth() const = 0;
    virtual float GetHeigth() const = 0;
    virtual const IOuterBoundaryStore* GetOuterBoundary() const = 0;
    virtual IColission* GetColission() = 0;
    virtual ITank* GetTank() = 0;
    virtual RenderParam* GetRenderParam() = 0;
    virtual IProjectileStore* GetProjectileStore() = 0;

    virtual void Update() = 0;
};


#endif // ISCENE

