//
//  theRoom.h
//  monteCarlo
//
//  Created by Daniel Holst on 2015-09-25.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#ifndef __monteCarlo__theRoom__
#define __monteCarlo__theRoom__

#include <stdio.h>
#include <vector>
#include "sceneObject.h"

class TheRoom
{
public:
    
    TheRoom();
    
    std::vector<SceneObject*> *sceneObjects;
};
#endif /* defined(__monteCarlo__theRoom__) */
