//
//  bat.cpp
//  Pong
//
//  Actual function definitions relating to the bat object.
//
//  Created by Mrinank Sharma on 07/01/2020.
//  Copyright © 2020 Mrinank Sharma. All rights reserved.
//

#include <stdio.h>
#include "bat.h"
 
// constructor method
Bat::Bat(float startX, float startY, int windowHeightIn)
{
    pos.x = startX;
    pos.y = startY;
 
    shape.setSize(sf::Vector2f(10, 100));
    shape.setPosition(pos);
    shape.setFillColor(sf::Color::White);
    
    windowHeight = windowHeightIn;
    
}

FloatRect Bat::getPosition()
{
    return shape.getGlobalBounds();
}
 
RectangleShape Bat::getShape()
{
    return shape;
}
 
void Bat::mvUp()
{
    pos.y -= batSpeed;
}
 
void Bat::mvDown()
{
    pos.y += batSpeed;
}

void Bat::setInBounds(){
    if (pos.y > (windowHeight - 100))
    {
        pos.y = windowHeight - 100;
    }
    else if (pos.y < 0)
    {
        pos.y = 0;
    }
}
 
void Bat::update()
{
    setInBounds();
    shape.setPosition(pos);
}
