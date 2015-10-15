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
#include "objectMaterial.h"

class IntersectionPoint
{
public:
    IntersectionPoint(glm::vec3 position, glm::vec3 normalVector, ObjectMaterial objMat);
    
    glm::vec3 getPos() {return pos;};
    
    ObjectMaterial getMaterial() { return material; };
    
    
private:
    glm::vec3 pos;
    glm::vec3 normal;
    
    ObjectMaterial material;
};

#endif /* defined(__monteCarlo__intersectionPoint__) */
