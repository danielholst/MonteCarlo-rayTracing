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

    float getImportance ();
    void setImportance (float im);
    
private:
                     
    glm::vec3 start;
    glm::vec3 direction;
    float minDist;
    int nrOfIntersections;
    float importance;
    
    void display(glm::vec3 pos);
};

#endif /* defined(__monteCarlo__ray__) */
