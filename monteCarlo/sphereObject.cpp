//
//  sphereObject.cpp
//  monteCarlo
//
//  Created by Daniel Holst on 2015-10-08.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#include "sphereObject.h"

SphereObject::SphereObject(float rad, glm::vec3 position) : SceneObject(position)
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
    step = glm::vec3(0.1, 0.1, 0.1);
    
//    std::cout << r.direction.x << " " << r.direction.y << " " << r.direction.z << std::endl;
    
    for( int i = 0; i < 100; i++)
    {
        rayPos += r.direction*step;
        if(checkDistance(rayPos, pos, radius))
        {
//            std::cout << "intersection at " << rayPos.x << "," << rayPos.y << std::endl;
            return new IntersectionPoint(rayPos, glm::vec3(0,0,0)); //change to normal vec for second arg
        }
    }
    
    return nullptr;
}
