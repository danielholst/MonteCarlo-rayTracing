//
//  intersectionPoint.cpp
//  monteCarlo
//
//  Created by Daniel Holst on 2015-10-13.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#include "intersectionPoint.h"

IntersectionPoint::IntersectionPoint(glm::vec3 position, glm::vec3 normalVector, ObjectMaterial objMat)
{
    pos = position;
    normal = normalVector;
    material = objMat;
}