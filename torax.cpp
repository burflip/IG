#include "torax.h"

Torax::Torax()
{
    mouth_anim =0;
}

void Torax::draw()
{
    glPushMatrix();
    drawTorax();
    drawEyes();
    drawFangs();
    glPopMatrix();
}

void Torax::drawTorax()
{
    glPushMatrix();
    this->scale(1.9,0.8,2);
    this->is_red_when_chess = false;
    this->drawMode();
    this->drawSphere();
    glPopMatrix();
}

void Torax::drawEye()
{
    glPushMatrix();
    this->scale(0.1,0.1,0.1);
    this->is_red_when_chess = true;
    this->drawMode();
    this->drawSphere();
    glPopMatrix();
}

void Torax::drawEyes()
{
    glPushMatrix();
    this->translate(-0.4,0.6,1.8);
    this->scale(4,6.2,2.6);
    drawEye();
    glPopMatrix();
    glPushMatrix();
    this->translate(0.4,0.6,1.8);
    this->scale(4,6.2,2.6);
    drawEye();
    glPopMatrix();
    glPushMatrix();
    this->translate(1.2,0.6,1.4);
    this->scale(2,2.6,1.8);
    drawEye();
    glPopMatrix();
    glPushMatrix();
    this->translate(-1.2,0.6,1.4);
    this->scale(2,2.6,1.8);
    drawEye();
    glPopMatrix();
}

void Torax::drawFang()
{
    glPushMatrix();
    this->rotate(1,0,0,90);
    this->scale(0.3,0.3,0.5);
    this->is_red_when_chess = false;
    this->drawMode();
    this->drawCone();
    glPopMatrix();

    glPushMatrix();
    this->rotate(1,0,0,90);
    this->scale(0.3,0.3,0.6);
    this->translate(0,0,-1);
    this->is_red_when_chess = true;
    this->drawMode();
    this->drawCilinder();
    glPopMatrix();
}

void Torax::drawFangs()
{
    glPushMatrix();
    this->scale(1,1,1);
    this->translate(-0.6+(mouth_anim/100),-0.7,1.8);
    this->rotate(0,0,1,-20+mouth_anim);
    this->drawFang();
    glPopMatrix();
    glPushMatrix();
    this->scale(1,1,1);
    this->translate(0.6-(mouth_anim/100),-0.7,1.8);
    this->rotate(0,0,1,20-mouth_anim);
    this->drawFang();
    glPopMatrix();
}

