//
//  lightsource.cpp
//  monteCarlo
//
//  Created by Daniel Holst on 2015-10-13.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#include "lightsource.h"


Lightsource::Lightsource(glm::vec3 position, glm::vec3 direction, float strength)
{
    pos = position;
    dir = direction;
    lightEmitted = strength;
}