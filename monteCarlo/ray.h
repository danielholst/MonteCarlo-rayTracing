//
//  ray.h
//  monteCarlo
//
//  Created by Daniel Holst on 2015-09-25.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#ifndef __monteCarlo__ray__
#define __monteCarlo__ray__

#include "glm/glm/glm.hpp"
#include <stdio.h>

class Ray
{
public:
    Ray();
    Ray(glm::vec3 s, glm::vec3 dir);
    
private:
    glm::vec3 start;
    glm::vec3 direction;
};

#endif /* defined(__monteCarlo__ray__) */