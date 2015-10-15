//
//  camera.h
//  monteCarlo
//
//  Created by Daniel Holst on 2015-09-28.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#ifndef __monteCarlo__camera__
#define __monteCarlo__camera__

#include <stdio.h>
#include "glm/glm/glm.hpp"
#include "glm/glm/gtc/constants.hpp"
#include "sceneImage.h"
#include "ray.h"
#include "theRoom.h"

class Camera
{
public:
    Camera();
    
    void sendRaysThroughScene(TheRoom *room);
    
    
    
    glm::vec3 pos;
    glm::vec3 upDir;
    glm::vec3 dir;
    
    float fovX;
    float fovY;
    
    SceneImage *outputImage;
    
    
};
#endif /* defined(__monteCarlo__camera__) */
