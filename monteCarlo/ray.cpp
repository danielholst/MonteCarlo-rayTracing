//
//  ray.cpp
//  monteCarlo
//
//  Created by Daniel Holst on 2015-09-25.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#include "ray.h"

Ray::Ray() {}

Ray::Ray(glm::vec3 s, glm::vec3 dir)
{
    start = s;
    direction = glm::normalize(dir);
    minDist = 0;
}
