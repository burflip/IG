#include "body.h"

Body::Body()
{
}

void Body::draw()
{
    glPushMatrix();
    drawAbdomen();
    glPopMatrix();
}

void Body::drawAbdomen()
{
    glPushMatrix();
    this->scale(3.8,2.3,4);
    this->is_red_when_chess = false;
    this->drawMode();
    this->drawSphere();
    glPopMatrix();
}
