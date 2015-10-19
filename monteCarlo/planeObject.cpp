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

IntersectionPoint* PlaneObject::intersection(Ray r)
{
    glm::vec3 rayPos = r.start;
    glm::vec3 step;
    step = glm::vec3(0.01, 0.01, 0.01);
//    rayPos += r.direction + r.direction + r.direction;
   
    for( int i = 0; i < 650; i++)
    {
        rayPos += r.direction*step;
        if( i > 50 && checkHit(rayPos, pos, lengthX, lengthY, lengthZ))
        {
//            std::cout << "number of steps: " << i << std::endl;
            //to see which intersection is closest to the camera
            if( r.minDist == 0 || rayPos.z < r.minDist)
            {
                r.minDist = rayPos.z;
//                std::cout << rayPos.z << std::endl;
                return new IntersectionPoint(rayPos, normalVec, material);
            }
            
            if( i == 649)
                std::cout << "end of ray" << std::endl;
        }
    }
    
    return nullptr;
}
