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

IntersectionPoint* SphereObject::intersection(glm::vec3 rayPos)
{
    if(checkDistance(rayPos, pos, radius))
    {
//        std::cout << pos.x << ":" << pos.y << ":" << pos.z << std::endl;
        glm::vec3 norVec = glm::normalize(rayPos - pos);
        return new IntersectionPoint(rayPos, norVec, material); //change to normal vec for second arg
    }
    
    return nullptr;
}

//To find intersection point with ray
IntersectionPoint* SphereObject::intersection2(Ray r)
{
    glm::vec3 L = getPos()- r.getStart();
    
    float tca = glm::dot(L, r.getDir());
    
    //if object is behind ray
    if(tca < 0)
        return nullptr;
    
    float d = glm::dot(L, L) - tca*tca;
    
    //if ray miss the object
    if( d > getRadius())
        return nullptr;
    
    float thc = sqrt(getRadius() - d);
    
    // distance to intersection point
    float t = tca - thc;
    
    // if there is another object in front
    if (t > r.getMinDist() )
        return nullptr;
    else
        r.setMinDist(t);
    
    glm::vec3 posOfIntersection = r.getStart() + r.getDir() * t - r.getDir() * glm::vec3(0.01,0.01,0.01);
    glm::vec3 norVec = glm::normalize(posOfIntersection - pos);
    
    return new IntersectionPoint(posOfIntersection, norVec, material);
    
}