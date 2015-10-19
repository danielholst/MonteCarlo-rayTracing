//
//  sphereObject.cpp
//  monteCarlo
//
//  Created by Daniel Holst on 2015-10-08.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#include "sphereObject.h"

SphereObject::SphereObject(float rad, glm::vec3 position, ObjectMaterial objMat, glm::vec3 normal) : SceneObject(position, objMat, normal)
{
    radius = rad;
}

//check if surface is hit of sphere
bool checkDistance(glm::vec3 pos, glm::vec3 center, float radius)
{
    if(sqrt( pow(pos.x-center.x, 2) + pow(pos.y-center.y, 2) + pow(pos.z-center.z, 2)) < radius)
        return true;
    else
        return false;
}

IntersectionPoint* SphereObject::intersection(Ray r)
{
    glm::vec3 rayPos = r.start;
    glm::vec3 step;
    step = glm::vec3(0.01, 0.01, 0.01);
    
    rayPos += r.direction*step + r.direction*step + r.direction*step;
    
//    r.display(rayPos);
    
    for( int i = 0; i < 600; i++)
    {
        rayPos += r.direction*step;
        if(checkDistance(rayPos, pos, radius))
        {
            //to see which intersection is closest to the camera
            if( r.minDist == 0 || rayPos.z < r.minDist)
            {
                r.minDist = rayPos.z;
                glm::vec3 norVec = rayPos - pos;
                return new IntersectionPoint(rayPos, norVec, material); //change to normal vec for second arg
            }
        }
    }
    
    return nullptr;
}
