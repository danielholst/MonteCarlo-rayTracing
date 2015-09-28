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

class Camera
{
public:
    Camera();
    
    glm::vec3 pos;
    glm::vec3 dir;
    
    
};
#endif /* defined(__monteCarlo__camera__) */
