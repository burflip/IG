#include "_3dhbasicelement.h"



#include <GL/glut.h>
#include <GL/gl.h>
#include <vertex.h>

using namespace std;

bool _3dHBasicElement::chess = false;

_3dHBasicElement::_3dHBasicElement()
{
    base_color = _vertex3f(0,1,0);
    drawing_mode = 0;
    is_red_when_chess = false;
}

_3dHBasicElement::_3dHBasicElement(float x, float y, float z)
{
    _3dHBasicElement();
    translate(x,y,z);
}

void _3dHBasicElement::drawPoints()
{
    glPointSize(3);
    glColor3f(base_color.x,base_color.y,base_color.z);
    glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
}

void _3dHBasicElement::drawWire()
{
    glColor3f(base_color.x,base_color.y,base_color.z);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void _3dHBasicElement::drawSolid()
{
    glColor3f(base_color.x,base_color.y,base_color.z);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
}

void _3dHBasicElement::drawChess()
{
    const _vertex3f color_chess_red(1,0,0);
    const _vertex3f color_chess_blue(0,0,1);
    if(is_red_when_chess) {
        glColor3f(color_chess_red.x,color_chess_red.y,color_chess_red.z);
    } else {
        glColor3f(color_chess_blue.x,color_chess_blue.y,color_chess_blue.z);
    }

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
}

void _3dHBasicElement::drawMode()
{
    switch(this->drawing_mode) {
    case PUNTOS:
        drawPoints();
        break;
    case ALAMBRE:
        drawWire();
        break;
    case SOLIDO:
        drawSolid();
        break;
    case AJEDREZ:
        drawChess();
        break;
    }
}

void _3dHBasicElement::draw()
{

}

void _3dHBasicElement::drawCube(float r)
{
    glutSolidCube(r);
}

void _3dHBasicElement::drawSphere(float r, int slices, int stacks)
{
    glutSolidSphere(r,slices,stacks);
}

void _3dHBasicElement::drawCilinder(float r, float h, float t, int slices, int stacks)
{
    if(t == 0.0) {
        t = r;
    }
    static GLUquadricObj * qobj = NULL;
    if(qobj==NULL)
        qobj= gluNewQuadric();

    gluQuadricDrawStyle(qobj,GLU_FILL);
    gluCylinder(qobj,r,h,t,slices,stacks);
}

void _3dHBasicElement::drawCone(float r, float h, int slices, int stacks)
{
    glutSolidCone(r,h,slices,stacks);
}

void _3dHBasicElement::scale(float x, float y, float z)
{
    glScalef(x,y,z);
}

void _3dHBasicElement::translate(float x, float y, float z)
{
    glTranslatef(x,y,z);
}

void _3dHBasicElement::rotate(float x, float y, float z, float angle)
{
    glRotatef(angle,x,y,z);
}
