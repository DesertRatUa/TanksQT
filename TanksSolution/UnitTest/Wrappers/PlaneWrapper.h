#ifndef PLANEWRAPPER_H
#define PLANEWRAPPER_H

#include "MapObjects/IPlane.h"

class PlaneWrapper : public IPlane
{
public:
    PlaneWrapper();

    virtual float GetX() const;
    virtual float GetY() const;
    virtual float GetHeight() const;
    virtual float GetWidth() const;
    virtual std::string GetName() const;

    float m_x;
    float m_y;
    float m_height;
    float m_width;
    std::string m_name;
};

#endif // PLANEWRAPPER_H
