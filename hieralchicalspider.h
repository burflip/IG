#ifndef HIERALCHICALSPIDER_H
#define HIERALCHICALSPIDER_H

#include <_3dhbasicelement.h>
#include <leg.h>
#include <torax.h>
#include <body.h>

class HieralchicalSpider : public _3dHBasicElement
{
public:
    HieralchicalSpider();

    void draw();

    void setDrawingMode(int drawing_mode);

    void animate();

    void incrementLegsAnim();
    void incrementMouthAnim();
    void incrementHeadAnim();
    void decrementLegsAnim();
    void decrementMouthAnim();
    void decrementHeadAnim();

    void incrementLegsSpeed();
    void decrementLegsSpeed();
    void incrementHeadSpeed();
    void decrementHeadSpeed();
    void incrementMouthSpeed();
    void decrementMouthSpeed();

private:
    Leg legs;
    Torax torax;
    Body body;
    float legs_anim, mouth_anim, head_anim,
    legs_animation_multiplier,mouth_animation_multiplier,head_animation_multiplier,
    leg_speed,head_speed,mouth_speed;
    void animateLegs();
    void animateMouth();
    void animateHead();
    void drawLegs();
    void drawTorax();
    void drawBody();

};

#endif // HIERALCHICALSPIDER_H
