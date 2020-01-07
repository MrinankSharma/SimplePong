//
//  ball.cpp
//  Pong
//
//  Created by Mrinank Sharma on 07/01/2020.
//  Copyright © 2020 Mrinank Sharma. All rights reserved.
//

#include "ball.h"

// constructor method
Ball::Ball(float startX, float startY)
{
    position.x = startX;
    position.y = startY;
 
    ballShape.setSize(sf::Vector2f(size, size));
    ballShape.setPosition(position);
}

FloatRect Ball::getPosition()
{
    return ballShape.getGlobalBounds();
}
 
RectangleShape Ball::getShape()
{
    return ballShape;
}
 
float Ball::getXVelocity()
{
    return xVelocity;
}
 
int Ball::getSize(){
    return size;
}

void Ball::reboundBat()
{
    //if the bat has been hit, reverse the X velocity
    xVelocity = -xVelocity;
}
 
void Ball::reboundTopOrBottom()
{
    // move the bat sufficiently away from the top or bottom
    position.y -= (yVelocity * 30);
    // reverse y velocity when
    yVelocity = -yVelocity;
 
}
 
void Ball::center()
{
    position.y = 400;
    position.x = 600;

    // reset for more fun.
    xVelocity = -xVelocity;
    yVelocity = -yVelocity;
}

void Ball::update()
{
    // Update the ball position variables
    position.y += yVelocity;
    position.x += xVelocity;
 
    // Move the ball and the bat
    ballShape.setPosition(position);
}
