#ifndef BODY_H
#define BODY_H


#include <_3dhbasicelement.h>

class Body : public _3dHBasicElement
{
public:
    Body();

    void draw();

    void drawAbdomen();
};

#endif // BODY_H
