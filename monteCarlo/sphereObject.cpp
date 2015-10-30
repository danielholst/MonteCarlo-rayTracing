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

//To find intersection point with ray
IntersectionPoint* SphereObject::intersection2(Ray &r)
{
    glm::vec3 L = getPos() - r.getStart();
    
    float tca = glm::dot(L, r.getDir());
    
    //if object is behind ray
    if(tca < 0)
        return nullptr;
    
    float d = glm::dot(L, L) - tca*tca;
    
    //if ray miss the object
    if( d > pow(getRadius(), 2))
        return nullptr;
    
    float thc = sqrt(pow(getRadius(),2) - d);
    
    // distance to intersection point
    float t1 = tca - thc;
    float t2 = tca + thc;

    if(t1 < 0)
    {
        t1 = t2;
        if(t1 < 0)
            return nullptr;
    }
    
    // if there is another object in front
    if (t1 > r.getMinDist() )
        return nullptr;
    else
        r.setMinDist(t1);

    glm::vec3 posOfIntersection = r.getStart() + r.getDir() * t1 - r.getDir() * glm::vec3(0.08,0.08,0.08);

    glm::vec3 norVec = glm::normalize(posOfIntersection - getPos());
    
    return new IntersectionPoint(posOfIntersection, norVec, getMaterial());
    
}