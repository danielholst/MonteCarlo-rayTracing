//
//  planeObject.cpp
//  monteCarlo
//
//  Created by Daniel Holst on 2015-10-13.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#include "planeObject.h"

PlaneObject::PlaneObject(glm::vec3 pos, float x, float y, float z, ObjectMaterial objMat, glm::vec3 normal) : SceneObject(pos, objMat, normal)
{
    lengthX = x;
    lengthY = y;
    lengthZ = z;
}

bool checkHit(glm::vec3 rayPos, glm::vec3 pos, float lengthX, float lengthY, float lengthZ)
{
    
    if((rayPos.x > (pos.x - lengthX/2-0.01)) && (rayPos.x < (pos.x + lengthX/2+0.01)) &&
       (rayPos.y > (pos.y - lengthY/2-0.01)) && (rayPos.y < (pos.y + lengthY/2+0.01)) &&
       (rayPos.z > (pos.z - lengthZ/2-0.04)) && (rayPos.z < (pos.z + lengthZ/2+0.04)))
        return true;
    else
        return false;
}

IntersectionPoint* PlaneObject::intersection(glm::vec3 rayPos)
{
    if( checkHit(rayPos, pos, lengthX, lengthY, lengthZ))
    {
        return new IntersectionPoint(rayPos, normalVec, material);
    }
    
    return nullptr;
}
