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
#include "lightsource.h"

// class to collect all objects and lights in the scene
class TheRoom
{
public:
    
    //Constructor, create room
    TheRoom();
    
    //add lightsource to the scene
    void addLightsourceToScene(SceneObject *l);
    
    //add objects to the scene
    void addObjectToScene(SceneObject *obj);
    
    std::vector<SceneObject*> *sceneObjects;
    std::vector<SceneObject*> *lightSources;
};
#endif /* defined(__monteCarlo__theRoom__) */
