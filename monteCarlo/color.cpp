//
//  color.cpp
//  monteCarlo
//
//  Created by Daniel Holst on 2015-10-14.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#include "color.h"

Color::Color()
{
    r = 0;
    g = 0;
    b = 0;
}
Color::Color(float rC, float gC, float bC)
{
    r = rC;
    g = gC;
    b = bC;
}

Color Color::operator*(Color c)
{
    return Color(r*c.r, g*c.g, b*c.b );
}

Color Color::operator*(float c)
{
    return Color(r*c, g*c, b*c );
}

Color Color::operator+(Color c)
{
    return Color(r+c.r, g+c.g, b+c.b);
}

float Color::getR()
{
    return r;
}
float Color::getG()
{
    return g;
}
float Color::getB()
{
    return b;
}

void Color::print()
{
    std::cout << r << ", " << g << ", " << b << std::endl;
}