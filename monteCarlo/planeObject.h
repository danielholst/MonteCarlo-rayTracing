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
#include "intersectionPoint.h"
#include "objectMaterial.h"


class PlaneObject : public SceneObject
{
public:
    PlaneObject(glm::vec3 pos, float x, float y, float z, ObjectMaterial objMat);
    
    IntersectionPoint* intersection(Ray r);
    
    ObjectMaterial getMaterial();
    
private:
    float lengthX;
    float lengthY;
    float lengthZ;
    
    ObjectMaterial material;
    
    
};
#endif /* defined(__monteCarlo__planeObject__) */
