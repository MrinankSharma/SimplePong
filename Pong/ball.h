//
//  ball.h
//  Pong
//
//  Created by Mrinank Sharma on 07/01/2020.
//  Copyright © 2020 Mrinank Sharma. All rights reserved.
//

#pragma once
#include <SFML/Graphics.hpp>

#ifndef ball_h
#define ball_h
 
using namespace sf;
 
class Ball
{
private:
    Vector2f position;
    
    RectangleShape ballShape;
 
    float xVelocity = .2f;
    float yVelocity = .2f;
    
    int size = 15;
 
public:
    Ball(float startX, float startY);
    FloatRect getPosition();
    RectangleShape getShape();
    
    float getXVelocity();
    int getSize();
    
    void reboundBat();
    void reboundTopOrBottom();
 
    void center();
    
    void update();
};
#endif /* ball_h */
