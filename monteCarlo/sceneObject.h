//
//  sceneObject.h
//  monteCarlo
//
//  Created by Daniel Holst on 2015-09-28.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#ifndef __monteCarlo__sceneObject__
#define __monteCarlo__sceneObject__

#include <stdio.h>
#include "glm/glm/glm.hpp"

class SceneObject
{
public:
    SceneObject();
    
protected:
    glm::vec3 pos;
    
};

#endif /* defined(__monteCarlo__sceneObject__) */
