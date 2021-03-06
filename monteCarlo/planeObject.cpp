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

IntersectionPoint* PlaneObject::intersection2(Ray &r)
{
    float fixedPointInPlane;
    float lengthToPlane;
    glm::vec3 newPos;
    
    if (lengthX == 0)
    {
        fixedPointInPlane = getPos().x;
        
        //get length to plane
        lengthToPlane = (fixedPointInPlane - r.getStart().x)  / r.getDir().x;
        
        //if intersection is in negative direction
        if ( lengthToPlane < 0.0f)
            return nullptr;
        
        //if another object is in the way
        if(lengthToPlane > r.getMinDist())
            return nullptr;
        
        //put in length to plane and see if the ray goes through plane
        if((r.getStart().y + lengthToPlane * r.getDir().y > getPos().y - lengthY/2) && (r.getStart().y + lengthToPlane * r.getDir().y < getPos().y + lengthY/2))
            if((r.getStart().z + lengthToPlane * r.getDir().z > getPos().z - lengthZ/2) && (r.getStart().z + lengthToPlane * r.getDir().z < getPos().z + lengthZ/2))
            {
                r.setMinDist(lengthToPlane);
                newPos = r.getStart() + lengthToPlane * r.getDir() - glm::vec3(0.01,0.01,0.01)*r.getDir();

                return new IntersectionPoint(newPos, getNormal(), getMaterial());
            }
    }
    else if(lengthY == 0)
    {
        fixedPointInPlane = getPos().y;
        lengthToPlane = (fixedPointInPlane - r.getStart().y)  / r.getDir().y;
       
        if ( lengthToPlane < 0.0f)
            return nullptr;
        
        if(lengthToPlane > r.getMinDist())
            return nullptr;
        
        if((r.getStart().x + lengthToPlane * r.getDir().x > getPos().x - lengthX/2) && (r.getStart().x + lengthToPlane * r.getDir().x < getPos().x + lengthX/2))
            if((r.getStart().z + lengthToPlane * r.getDir().z > getPos().z - lengthZ/2) && (r.getStart().z + lengthToPlane * r.getDir().z < getPos().z + lengthZ/2))
            {
                r.setMinDist(lengthToPlane);
                newPos = r.getStart() + lengthToPlane * r.getDir() - glm::vec3(0.01,0.01,0.01)*r.getDir();
                
                return new IntersectionPoint(newPos, getNormal(), getMaterial());
            }
    }
    else if(lengthZ == 0)
    {
        fixedPointInPlane = getPos().z;
        lengthToPlane = (fixedPointInPlane - r.getStart().z)  / r.getDir().z;

        if(lengthToPlane < 0)
            return nullptr;
        
        if(lengthToPlane > r.getMinDist())
            return nullptr;
        
        if((r.getStart().y + lengthToPlane * r.getDir().y > getPos().y - lengthY/2) && (r.getStart().y + lengthToPlane * r.getDir().y < getPos().y + lengthY/2))
            if((r.getStart().x + lengthToPlane * r.getDir().x > getPos().x - lengthX/2) && (r.getStart().x + lengthToPlane * r.getDir().x < getPos().x + lengthX/2))
            {
                r.setMinDist(lengthToPlane);
                newPos = r.getStart() + lengthToPlane * r.getDir() - glm::vec3(0.01,0.01,0.01)*r.getDir();
                
                return new IntersectionPoint(newPos, getNormal(), getMaterial());
            }
    }
    
    return nullptr;
    
}