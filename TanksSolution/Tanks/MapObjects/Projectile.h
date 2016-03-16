#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "IProjectile.h"

class Projectile : public IProjectile
{
public:
    Projectile( const RenderParam &param );

private:
    std::shared_ptr<QOpenGLTexture> m_texture;
};

#endif // PROJECTILE_H
