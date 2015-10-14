//
//  sphereObject.h
//  monteCarlo
//
//  Created by Daniel Holst on 2015-10-08.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#ifndef __monteCarlo__sphereObject__
#define __monteCarlo__sphereObject__

#include <stdio.h>
#include <iostream>
#include "sceneObject.h"
#include "intersectionPoint.h"
#include "ray.h"

class SphereObject : public SceneObject
{
public:
    SphereObject(float rad, glm::vec3 position);
    
    IntersectionPoint* intersection(Ray r);
    
private:
    float radius;
    
};
#endif /* defined(__monteCarlo__sphereObject__) */
