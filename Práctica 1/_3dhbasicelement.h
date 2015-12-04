#ifndef _3DHBASICELEMENT_H
#define _3DHBASICELEMENT_H

#define PUNTOS 0
#define ALAMBRE 1
#define SOLIDO 2
#define AJEDREZ 3
#define MEZCLA 4

#include <vertex.h>
#include <GL/glut.h>

class _3dHBasicElement
{
public:
    static const int SLICES = 20;
    static const int STACKS = 20;
    static bool chess;


    _3dHBasicElement();
    _3dHBasicElement(float x, float y, float z);

    void drawPoints();
    void drawWire();
    void drawSolid();
    void drawChess();
    void drawMode();

    inline void setDrawingMode(int d)
    {
        this->drawing_mode = d;
    }

    virtual void draw();

    void drawCube(float r=1);
    void drawSphere(float r=1, int slices=SLICES, int stacks=STACKS);
    void drawCilinder(float r=1,float h=1, float t=0.0, int slices=SLICES, int stacks=STACKS);
    void drawCone(float r=1,float h=1, int slices=SLICES, int stacks=STACKS);

    void scale(float x, float y, float z);
    void translate(float x, float y, float z);
    void rotate(float x, float y, float z, float angle);

protected:
    float x,y,z;
    _vertex3f base_color;
    int drawing_mode;
    bool is_red_when_chess;

};

#endif // _3DJBASICELEMENT_H
