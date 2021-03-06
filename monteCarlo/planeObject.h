//
//  planeObject.h
//  monteCarlo
//
//  Created by Daniel Holst on 2015-10-13.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#ifndef __monteCarlo__planeObject__
#define __monteCarlo__planeObject__

#include <stdio.h>
#include "sceneObject.h"
#include "glm/glm/glm.hpp"

// Plane object
class PlaneObject : public SceneObject
{
public:
    PlaneObject(glm::vec3 pos, float x, float y, float z, ObjectMaterial objMat, glm::vec3 normal);
    
    IntersectionPoint* intersection2(Ray &r);
    
private:
    float lengthX;
    float lengthY;
    float lengthZ;
    
};
#endif /* defined(__monteCarlo__planeObject__) */
