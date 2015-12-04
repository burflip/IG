#include "hieralchicalspider.h"

HieralchicalSpider::HieralchicalSpider()
{
    head_anim = mouth_anim = legs_anim = 0;
    legs_animation_multiplier = head_animation_multiplier = mouth_animation_multiplier = 1;
    leg_speed = head_speed = mouth_speed = 1;
}


void HieralchicalSpider::draw()
{
    if(this->drawing_mode == MEZCLA) {
        this->setDrawingMode(PUNTOS);
        draw();
        this->setDrawingMode(AJEDREZ);
        draw();
        this->setDrawingMode(ALAMBRE);
        draw();
        this->setDrawingMode(MEZCLA);
    } else {
        glPushMatrix();
        drawLegs();
        drawBody();
        drawTorax();
        glPopMatrix();
    }

}

void HieralchicalSpider::drawLegs()
{

    glPushMatrix();
    this->rotate(0,1,0,-60-(legs_anim*1.2));
    this->translate(1.6,0.4,-5.2);
    this->scale(2,2,3);
    legs.draw();
    glPopMatrix();
    glPushMatrix();
    this->rotate(0,1,0,-83-legs_anim);
    this->translate(1.7,0.4,-4);
    this->scale(2,2,2);
    legs.draw();
    glPopMatrix();
    glPushMatrix();
    this->rotate(0,1,0,-96-legs_anim);
    this->translate(2,0.4,-4.6);
    this->scale(2,2,2);
    legs.draw();
    glPopMatrix();
    glPushMatrix();
    this->rotate(0,1,0,-114-(legs_anim*0.8));
    this->translate(2,0.4,-5);
    this->scale(2,2,1.7);
    legs.draw();
    glPopMatrix();

    //Parte derecha

    glPushMatrix();
    this->rotate(0,1,0,60+(legs_anim*1.2));
    this->translate(-1.6,0.4,-5.2);
    this->scale(2,2,3);
    legs.draw();
    glPopMatrix();
    glPushMatrix();
    this->rotate(0,1,0,83+legs_anim);
    this->translate(-1.7,0.4,-4);
    this->scale(2,2,2);
    legs.draw();
    glPopMatrix();
    glPushMatrix();
    this->rotate(0,1,0,96+legs_anim);
    this->translate(-2,0.4,-4.6);
    this->scale(2,2,2);
    legs.draw();
    glPopMatrix();
    glPushMatrix();
    this->rotate(0,1,0,114+(legs_anim*0.8));
    this->translate(-2,0.4,-5);
    this->scale(2,2,1.7);
    legs.draw();
    glPopMatrix();
}

void HieralchicalSpider::drawTorax()
{
    glPushMatrix();
    this->translate(0,0,2);
    this->rotate(0,1,0,0+head_anim);
    torax.setMouthAnim(mouth_anim);
    torax.draw();
    glPopMatrix();
}

void HieralchicalSpider::drawBody()
{
    glPushMatrix();
    this->translate(0,0,-3);
    body.draw();
    glPopMatrix();
}

void HieralchicalSpider::setDrawingMode(int d)
{
    this->drawing_mode = d;
    legs.setDrawingMode(this->drawing_mode);
    torax.setDrawingMode(this->drawing_mode);
    body.setDrawingMode(this->drawing_mode);
}

void HieralchicalSpider::animate()
{
    animateMouth();
    animateLegs();
    animateHead();
}

void HieralchicalSpider::animateLegs()
{

    if(this->legs_anim >= 8)
    {
        this->legs_animation_multiplier=-1*leg_speed;
    } else if(this->legs_anim <= -8) {
        this->legs_animation_multiplier=1*leg_speed;
    }

    this->legs_anim +=0.3*legs_animation_multiplier;
}

void HieralchicalSpider::animateMouth()
{
    if(this->mouth_anim >= 20)
    {
        this->mouth_animation_multiplier=-1*mouth_speed;
    } else if(this->mouth_anim <= -20) {
        this->mouth_animation_multiplier=2*mouth_speed;
    }

    this->mouth_anim +=mouth_animation_multiplier;
}

void HieralchicalSpider::animateHead()
{

    if(this->head_anim >= 10)
    {
        this->head_animation_multiplier=-1*head_speed;
    } else if(this->head_anim <= -10) {
        this->head_animation_multiplier=1*head_speed;
    }

    this->head_anim +=0.5*head_animation_multiplier;
}



void HieralchicalSpider::incrementLegsAnim()
{
    if(this->legs_anim < 8)
    {
        this->legs_anim +=0.5*leg_speed;
    }
}

void HieralchicalSpider::incrementMouthAnim()
{
    if(this->mouth_anim < 20)
    {
        this->mouth_anim +=1*mouth_speed;
    }
}

void HieralchicalSpider::incrementHeadAnim()
{
    if(this->head_anim < 10)
    {
        this->head_anim +=0.5*head_speed;
    }
}

void HieralchicalSpider::decrementLegsAnim()
{
    if(this->legs_anim > -8)
    {
        this->legs_anim -=0.5*leg_speed;
    }
}

void HieralchicalSpider::decrementMouthAnim()
{
    if(this->mouth_anim > -20)
    {
        this->mouth_anim -=1*mouth_speed;
    }
}

void HieralchicalSpider::decrementHeadAnim()
{
    if(this->head_anim > -10)
    {
        this->head_anim -=0.5*head_speed;
    }
}

void HieralchicalSpider::incrementLegsSpeed()
{
    if(this->leg_speed <= 2) {
        this->leg_speed+=0.1;
    }
}

void HieralchicalSpider::decrementLegsSpeed()
{
    if(this->leg_speed >= 0 && this->leg_speed > 0.1) {
        this->leg_speed-=0.1;
    } else if(this->leg_speed >= 0 && this->leg_speed < 0.1) {
        this->leg_speed = 0;
    }
}

void HieralchicalSpider::incrementHeadSpeed()
{
    if(this->head_speed <= 2) {
        this->head_speed+=0.1;
    }
}

void HieralchicalSpider::decrementHeadSpeed()
{
    if(this->head_speed >= 0) {
        this->head_speed-=0.1;
    } else if(this->head_speed >= 0 && this->head_speed < 0.1) {
        this->head_speed = 0;
    }
}

void HieralchicalSpider::incrementMouthSpeed()
{
    if(this->mouth_speed <= 2) {
        this->mouth_speed+=0.1;
    }
}

void HieralchicalSpider::decrementMouthSpeed()
{
    if(this->mouth_speed >= 0) {
        this->mouth_speed-=0.1;
    } else if(this->mouth_speed >= 0 && this->mouth_speed < 0.1) {
        this->mouth_speed = 0;
    }
}
