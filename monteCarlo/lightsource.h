//
//  lightsource.h
//  monteCarlo
//
//  Created by Daniel Holst on 2015-10-13.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

//NOT USED ATM

#ifndef __monteCarlo__lightsource__
#define __monteCarlo__lightsource__

#include <stdio.h>
#include "glm/glm/glm.hpp"
#include "color.h"

class Lightsource
{
public:
    Lightsource(float rad, glm::vec3 position, glm::vec3 direction, Color c);

    glm::vec3 getPos() { return pos; };

    Color getColor() { return color; };
    
    float getRadius() {return radius; };

private:
    float radius;
    glm::vec3 pos;
    glm::vec3 dir;
    Color color;
};

#endif /* defined(__monteCarlo__lightsource__) */
