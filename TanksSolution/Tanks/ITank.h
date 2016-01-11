#ifndef ITANK
#define ITANK

struct RenderParam;

class ITank
{
public:
    virtual ~ITank() {}

    virtual void Init( RenderParam &param ) = 0;
    virtual void Draw() = 0;

    virtual void MoveUp() = 0;
    virtual void MoveDown() = 0;
    virtual void MoveLeft() = 0;
    virtual void MoveRight() = 0;
};

#endif // ITANK

