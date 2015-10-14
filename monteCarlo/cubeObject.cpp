//
//  cubeObject.cpp
//  monteCarlo
//
//  Created by Daniel Holst on 2015-10-07.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#include "cubeObject.h"

CubeObject::CubeObject(glm::vec3 position, glm::vec3 objectScale) : SceneObject(position)
{
    scale = objectScale;
}

IntersectionPoint* CubeObject::intersection(Ray r)
{
    glm::vec3 rayPos;

    return nullptr;
}