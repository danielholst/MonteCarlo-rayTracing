//
//  camera.cpp
//  monteCarlo
//
//  Created by Daniel Holst on 2015-09-28.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#include "camera.h"

Camera::Camera()
{
    pos = glm::vec3(0,0,0);
    dir = glm::vec3(0,0,-1);
}