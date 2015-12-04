#include "leg.h"

Leg::Leg()
{
}

void Leg::draw()
{
    glPushMatrix();
    this->translate(0,0,-0.8);
    this->drawKnee();
    this->drawTop();
    this->drawBot();
    glPopMatrix();
}

void Leg::drawTop()
{
    glPushMatrix();
    this->translate(0,0.6,1.5);
    this->rotate(1,0,0,-40);
    this->is_red_when_chess = true;
    this->drawMode();
    this->drawBone(2.2);
    glPopMatrix();
}

void Leg::drawKnee()
{
    glPushMatrix();
    this->scale(0.2,0.2,0.2);
    this->translate(0,7,4);
    this->drawMode();
    this->is_red_when_chess = false;
    this->drawMode();
    this->drawSphere();
    glPopMatrix();
}

void Leg::drawBot()
{
    glPushMatrix();
    this->rotate(1,0,0,30);
    this->is_red_when_chess = true;
    this->drawMode();
    this->drawBone(3.2);
    glPopMatrix();
}

void Leg::drawBone(float size)
{
    glPushMatrix();
    this->scale(0.3,size,0.3);
    this->drawCube();
    glPopMatrix();
}
