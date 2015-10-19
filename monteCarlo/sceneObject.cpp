//
//  sceneObject.cpp
//  monteCarlo
//
//  Created by Daniel Holst on 2015-09-28.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#include "sceneObject.h"

SceneObject::SceneObject(glm::vec3 position, ObjectMaterial objMat, glm::vec3 normal)
{
    pos = position;
    material = objMat;
    normalVec = normal;
};


glm::vec3 SceneObject::getPos()
{
    return pos;
}


ObjectMaterial SceneObject::getMaterial()
{
    return material;
}

glm::vec3 SceneObject::getNormal()
{
    return normalVec;
}