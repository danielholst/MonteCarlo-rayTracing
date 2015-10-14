//
//  planeObject.cpp
//  monteCarlo
//
//  Created by Daniel Holst on 2015-10-13.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#include "planeObject.h"

PlaneObject::PlaneObject(glm::vec3 pos, float x, float y, float z, ObjectMaterial objMat) : SceneObject(pos)
{
    lengthX = x;
    lengthY = y;
    lengthZ = z;
    
    material = objMat;
}

bool checkHit(glm::vec3 rayPos, glm::vec3 pos, float lengthX, float lengthY, float lengthZ)
{
//    std::cout << rayPos.x << ", " << rayPos.y << ", " << rayPos.z << std::endl;
    
    if((rayPos.x > (pos.x - lengthX/2-0.03)) && (rayPos.x < (pos.x + lengthX/2+0.03)) &&
       (rayPos.y > (pos.y - lengthY/2-0.03)) && (rayPos.y < (pos.y + lengthY/2+0.03)) &&
       (rayPos.z > (pos.z - lengthZ/2-0.05)) && (rayPos.z < (pos.z + lengthZ/2+0.05)))
        return true;
    else
        return false;
}

IntersectionPoint* PlaneObject::intersection(Ray r)
{
    glm::vec3 rayPos = r.start;
    glm::vec3 step;
    step = glm::vec3(0.1, 0.1, 0.1);
   
    for( int i = 0; i < 100; i++)
    {
        rayPos += r.direction*step;
        if(checkHit(rayPos, pos, lengthX, lengthY, lengthZ))
        {
//            std::cout << "Hit" << std::endl;
            return new IntersectionPoint(rayPos, glm::vec3(0,0,0)); //change to normal vec for second arg
        }
    }
    
    return nullptr;
}

ObjectMaterial PlaneObject::getMaterial()
{
    return material;
}