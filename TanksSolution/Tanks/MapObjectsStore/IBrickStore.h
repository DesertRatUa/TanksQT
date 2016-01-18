#ifndef IBRICKSTORE_H
#define IBRICKSTORE_H

class IBrickStore
{
public:
    virtual ~IBrickStore() {}

    virtual void Init( const RenderParam &param ) = 0;
    virtual void Draw() = 0;
    virtual void Clear() = 0;
};

#endif // IBRICKSTORE_H

