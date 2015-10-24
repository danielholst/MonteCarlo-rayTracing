//
//  cubeObject.cpp
//  monteCarlo
//
//  Created by Daniel Holst on 2015-10-07.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#include "cubeObject.h"

CubeObject::CubeObject(glm::vec3 position, float x, float y, float z, ObjectMaterial objMat, glm::vec3 normal) : SceneObject(position, objMat, normal)
{
    //scale = objectScale;
    lengthX = x;
    lengthY = y;
    lengthZ = z;
}

bool checkIfHit(glm::vec3 rayPos, glm::vec3 pos, float lengthX, float lengthY, float lengthZ)
{

    if((rayPos.x > (pos.x - lengthX/2-0.01)) && (rayPos.x < (pos.x + lengthX/2+0.01)) &&
       (rayPos.y > (pos.y - lengthY/2-0.01)) && (rayPos.y < (pos.y + lengthY/2+0.01)) &&
       (rayPos.z > (pos.z - lengthZ/2-0.04)) && (rayPos.z < (pos.z + lengthZ/2+0.04)))
        return true;
    else
        return false;
}

IntersectionPoint* CubeObject::intersection(glm::vec3 rayPos)
{
    if( checkIfHit(rayPos, getPos(), lengthX, lengthY, lengthZ))
    {
        return new IntersectionPoint(rayPos, getNormal(), getMaterial());
    }

    return nullptr;
}




