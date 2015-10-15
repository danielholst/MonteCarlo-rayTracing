//
//  main.cpp
//  monteCarlo
//
//  Created by Daniel Holst on 2015-09-24.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GLUT/glut.h>

#include "theRoom.h"
#include "camera.h"
#include "ray.h"
#include "sphereObject.h"
#include "cubeObject.h"
#include "lightsource.h"
#include "planeObject.h"

int main(int argc, char** argv)
{
    //init enviroment and camera
    TheRoom *room = new TheRoom();
    Camera *camera = new Camera();
    
    SceneObject *object;
    
    //Add walls to room
    ObjectMaterial mat = ObjectMaterial(0, 0, Color(0, 200, 0));
    object = new PlaneObject(glm::vec3(-1.5, 0, -4), 0, 2, 3, mat);
    room->addObjectToScene(object);
    
    mat = ObjectMaterial(0, 0, Color(200, 0, 0));
    object = new PlaneObject(glm::vec3(1.5, 0, -4), 0, 2, 3, mat);
    room->addObjectToScene(object);
    
    mat = ObjectMaterial(0, 0, Color(200, 200, 200));
    object = new PlaneObject(glm::vec3(0, 0, -5.5), 3, 2, 0, mat);
    room->addObjectToScene(object);
    
    //Add floor and roof
    object = new PlaneObject(glm::vec3(0, -1, -4), 3, 0, 3, mat);
    room->addObjectToScene(object);
    
    object = new PlaneObject(glm::vec3(0, 1, -4), 3, 0, 3, mat);
    room->addObjectToScene(object);
    
    
    //Add lightsource to scene
    Lightsource *light = new Lightsource(glm::vec3(0, 4, -4), glm::vec3(0, -1, 0), 5);
    room->addLightsourceToScene(light);
    
    
    //Add spheres in scene
    ObjectMaterial matSphere = ObjectMaterial(0,0, Color(200, 0, 0));
    object = new SphereObject(0.3f, glm::vec3(0.3,0, -3), matSphere);
    room->addObjectToScene(object);
    
    object = new SphereObject(0.4f, glm::vec3(-0.3, 0.5, -4), matSphere);
    room->addObjectToScene(object);
    
    //send rays from camera out to scene and save as pnm image
    camera->sendRaysThroughScene(room);
    
    return 0;
}