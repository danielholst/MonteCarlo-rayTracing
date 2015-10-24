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

IntersectionPoint* PlaneObject::intersection2(Ray r)
{
    float fixedPointInPlane;
    float lengthToPlane;
    if (lengthX == 0)
    {
        fixedPointInPlane = getPos().x;
        
        //get length to plane
        lengthToPlane = fixedPointInPlane / r.getDir().x - r.getStart().x;
        
        //put in length to plane and see if the ray goes through plane
        if((r.getStart().y + lengthToPlane * r.getDir().y > getPos().y - lengthY/2) && (r.getStart().y + lengthToPlane * r.getDir().y < getPos().y + lengthY/2))
            if((r.getStart().z + lengthToPlane * r.getDir().z > getPos().z - lengthZ/2) && (r.getStart().z + lengthToPlane * r.getDir().z < getPos().z + lengthZ/2))
            {
                return new IntersectionPoint(glm::vec3(r.getStart() + lengthToPlane*r.getDir()), getNormal(), getMaterial());
            }
    }
    else if(lengthY == 0)
    {
        fixedPointInPlane = getPos().y;
        lengthToPlane = fixedPointInPlane / r.getDir().y - r.getStart().y;
        
        if((r.getStart().x + lengthToPlane * r.getDir().x > getPos().x - lengthX/2) && (r.getStart().x + lengthToPlane * r.getDir().x < getPos().x + lengthX/2))
            if((r.getStart().z + lengthToPlane * r.getDir().z > getPos().z - lengthZ/2) && (r.getStart().z + lengthToPlane * r.getDir().z < getPos().z + lengthZ/2))
            {
                return new IntersectionPoint(glm::vec3(r.getStart() + lengthToPlane*r.getDir()), getNormal(), getMaterial());
            }
    }
    else if(lengthZ == 0)
    {
        fixedPointInPlane = getPos().z;
        lengthToPlane = fixedPointInPlane / r.getDir().z - r.getStart().z;
        
        if((r.getStart().y + lengthToPlane * r.getDir().y > getPos().y - lengthY/2) && (r.getStart().y + lengthToPlane * r.getDir().y < getPos().y + lengthY/2))
            if((r.getStart().x + lengthToPlane * r.getDir().x > getPos().x - lengthX/2) && (r.getStart().x + lengthToPlane * r.getDir().x < getPos().x + lengthX/2))
            {
                return new IntersectionPoint(glm::vec3(r.getStart() + lengthToPlane*r.getDir()), getNormal(), getMaterial());
            }
    }
    
    std::cout << "wrong format on plane" << std::endl;
    return nullptr;
    
}