//
//  cubeObject.h
//  monteCarlo
//
//  Created by Daniel Holst on 2015-10-07.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#ifndef __monteCarlo__cubeObject__
#define __monteCarlo__cubeObject__

#include <stdio.h>
#include "sceneObject.h"
#include "ray.h"
#include "intersectionPoint.h"

class CubeObject : public SceneObject
{
public:
    CubeObject(glm::vec3 position, glm::vec3 objectScale, ObjectMaterial objMat, glm::vec3 normal);
    
    IntersectionPoint* intersection(Ray r);
    
private:
    glm::vec3 pos;
    glm::vec3 scale;    //not scale but maybe mat4 of corner vertices
};

#endif /* defined(__monteCarlo__cubeObject__) */
