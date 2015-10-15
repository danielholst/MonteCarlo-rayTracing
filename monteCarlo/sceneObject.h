//
//  sceneObject.h
//  monteCarlo
//
//  Created by Daniel Holst on 2015-09-28.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#ifndef __monteCarlo__sceneObject__
#define __monteCarlo__sceneObject__

#include <stdio.h>
#include <cmath>
#include <iostream>
#include "glm/glm/glm.hpp"
#include "ray.h"
#include "intersectionPoint.h"
#include "objectMaterial.h"

class SceneObject
{
public:
    SceneObject(glm::vec3 position, ObjectMaterial objMat);
    
    virtual IntersectionPoint* intersection(Ray r) = 0;
    
    glm::vec3 getPos();
    
    ObjectMaterial getMaterial();
    
protected:
    glm::vec3 pos;
    
    ObjectMaterial material;
    
};

#endif /* defined(__monteCarlo__sceneObject__) */
