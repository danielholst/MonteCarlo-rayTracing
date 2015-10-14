//
//  intersectionPoint.h
//  monteCarlo
//
//  Created by Daniel Holst on 2015-10-13.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#ifndef __monteCarlo__intersectionPoint__
#define __monteCarlo__intersectionPoint__

#include <stdio.h>
#include "glm/glm/glm.hpp"

class IntersectionPoint
{
public:
    IntersectionPoint(glm::vec3 position, glm::vec3 normalVector);
    
    glm::vec3 getPos() {return pos;};
    
    
private:
    glm::vec3 pos;
    glm::vec3 normal;
};

#endif /* defined(__monteCarlo__intersectionPoint__) */
