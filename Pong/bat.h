//
//  bat.h
//  Pong
//
//  Define bat interface.
//
//  Created by Mrinank Sharma on 07/01/2020.
//  Copyright © 2020 Mrinank Sharma. All rights reserved.
//

// only add once
#pragma once
#include <SFML/Graphics.hpp>

#ifndef bat_h
#define bat_h

using namespace sf;

class Bat{
private:
    Vector2f pos;
    RectangleShape shape;
    float batSpeed = 0.3f;
    int windowHeight;
    
    void setInBounds();
    
public:
    Bat(float startX, float startY, int windowHeightIn);
    FloatRect getPosition();
    RectangleShape getShape();
    void mvUp();
    void mvDown();
    void update();
};
#endif /* bat_h */
