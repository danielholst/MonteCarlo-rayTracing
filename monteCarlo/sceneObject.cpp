//
//  sceneObject.cpp
//  monteCarlo
//
//  Created by Daniel Holst on 2015-09-28.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#include "sceneObject.h"

SceneObject::SceneObject(glm::vec3 position)
{
    pos = position;
};


glm::vec3 SceneObject::getPos()
{
    return pos;
}
//
//IntersectionPoint* SceneObject::intersection(Ray r)
//{
//    std::cout << "in Sceneobject " << std::endl;
//    return nullptr;
//}