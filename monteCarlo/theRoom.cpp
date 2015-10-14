//
//  theRoom.cpp
//  monteCarlo
//
//  Created by Daniel Holst on 2015-09-25.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#include "theRoom.h"

TheRoom::TheRoom()
{
    sceneObjects = new std::vector<SceneObject*>();
    lightSources = new std::vector<Lightsource*>();
};

void TheRoom::addLightsourceToScene(Lightsource *l)
{
    lightSources->push_back(l);
}

void TheRoom::addObjectToScene(SceneObject *obj)
{
    sceneObjects->push_back(obj);
}