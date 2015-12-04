#ifndef LEG_H
#define LEG_H

#include <_3dhbasicelement.h>
#include <vertex.h>

class Leg : public _3dHBasicElement
{
public:
    Leg();
    void draw();
    void drawTop();
    void drawKnee();
    void drawBot();
    void drawBone(float size);
};

#endif // LEG_H
