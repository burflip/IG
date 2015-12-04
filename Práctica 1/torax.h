#ifndef TORAX_H
#define TORAX_H

#include <_3dhbasicelement.h>
#include <vertex.h>

class Torax : public _3dHBasicElement
{
public:
    Torax();

    void draw();

    void drawTorax();
    void drawLegAppendices();
    void drawLegAppendix();
    void drawEye();
    void drawEyes();
    void drawFangs();
    void drawFang();

    inline void setMouthAnim(float m)
    {
        this->mouth_anim = m;
    }

private:
    float mouth_anim;

};

#endif // TORAX_H
