//
//  lightsource.cpp
//  monteCarlo
//
//  Created by Daniel Holst on 2015-10-13.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#include "lightsource.h"


Lightsource::Lightsource(float rad, glm::vec3 position, glm::vec3 direction, Color c)
{
    radius = rad;
    pos = position;
    dir = direction;
    color = c;
}
