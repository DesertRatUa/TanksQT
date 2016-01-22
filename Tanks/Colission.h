#ifndef COLISSION_H
#define COLISSION_H
#include "IColission.h"
#include "vector"

class IScene;
class IOuterBoundaryStore;

class Colission : public IColission
{
public:
    Colission( const IScene &scene );

    virtual bool CheckMovement(MovementParams &param) const throw (std::runtime_error);

    virtual void AddColissionObject( const TiPlanePtr &plane ) throw (std::runtime_error);
    virtual void RemoveColissionObject( const TiPlanePtr &plane ) throw (std::runtime_error);

    virtual void Clear();
    virtual unsigned Size() const;

protected:
    bool CheckOuterBoundary(MovementParams &param) const throw (std::runtime_error);
    bool CheckColissionObjects(MovementParams &param) const;

    typedef std::vector<TiPlanePtr> TPlanePtrVec;

    const IScene &m_scene;
    TPlanePtrVec m_colissionObjects;
};

#endif // COLISSION_H
