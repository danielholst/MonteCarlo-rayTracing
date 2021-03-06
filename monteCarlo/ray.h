//
//  ray.h
//  monteCarlo
//
//  Created by Daniel Holst on 2015-09-25.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#ifndef __monteCarlo__ray__
#define __monteCarlo__ray__

#include "glm/glm/glm.hpp"
#include <stdio.h>
#include <iostream>

// class for the ray that is sent through the scene
class Ray
{
public:
    
    Ray();
    
    //create ray with start position and direction
    Ray(glm::vec3 s, glm::vec3 dir);
    
    int getNrOfIntersection();
    void setDir(glm::vec3 dir);
    void setStart(glm::vec3 st);
    
    glm::vec3 getDir() { return direction; };
    glm::vec3 getStart() { return start; };
    
    float getMinDist() { return minDist; };
    void setMinDist(float dist) { minDist = dist; };

    float getImportance ();
    void setImportance (float im);
    
    void display(glm::vec3 pos);
    
private:
                     
    glm::vec3 start;
    glm::vec3 direction;
    float minDist;
    int nrOfIntersections;
    float importance;
};

#endif /* defined(__monteCarlo__ray__) */
