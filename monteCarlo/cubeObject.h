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
    CubeObject(glm::vec3 position, float x, float y, float z, ObjectMaterial objMat, glm::vec3 normal);

private:

    float lengthX;
    float lengthY;
    float lengthZ;
};

#endif /* defined(__monteCarlo__cubeObject__) */
