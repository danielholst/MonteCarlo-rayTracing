//
//  ray.cpp
//  monteCarlo
//
//  Created by Daniel Holst on 2015-09-25.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#include "ray.h"

Ray::Ray() {}

Ray::Ray(glm::vec3 s, glm::vec3 dir)
{
    start = s;
    direction = glm::normalize(dir);
    minDist = 0;
    nrOfIntersections = 0;
    importance = 1;
}

void Ray::display(glm::vec3 pos)
{
    std::cout << "ray position ( x = " << pos.x
              << ", y = " << pos.y
              << ", z = " << pos.z << std::endl;
}

int Ray::getNrOfIntersection()
{
    return nrOfIntersections;
}

void Ray::setDir(glm::vec3 dir)
{
    direction = dir;
}

void Ray::setStart(glm::vec3 st)
{
    start = st;
}

float Ray::getImportance()
{
    return importance;
}

void Ray::setImportance(float im)
{
    importance = im;
}