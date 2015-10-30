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

#include "theRoom.h"
#include "camera.h"
#include "ray.h"
#include "sphereObject.h"
#include "cubeObject.h"
#include "lightsource.h"
#include "planeObject.h"
#include <time.h>

int main(int argc, char** argv)
{

    //to see rendering time
    clock_t init, final;
    init=clock();

    //init enviroment and camera
    TheRoom *room = new TheRoom();
    Camera *camera = new Camera(1200,900);

    SceneObject *object;

    //Add spheres to scene
    ObjectMaterial matSphere = ObjectMaterial(0, 0,0.8, Color(30, 30, 30));
    object = new SphereObject(0.2f, glm::vec3(0.1,-0.7, -5), matSphere, glm::vec3(0,0,0));
    room->addObjectToScene(object);

    matSphere = ObjectMaterial(0, 0,0.5, Color(30,30,30));
    object = new SphereObject(0.3f, glm::vec3(-0.6, -0.5, -4), matSphere, glm::vec3(0,0,0));
    room->addObjectToScene(object);

    matSphere = ObjectMaterial(0, 0,0, Color(20,150,0));
    object = new SphereObject(0.3f, glm::vec3(0.8, -0.6, -4.5), matSphere, glm::vec3(0,0,0));
    room->addObjectToScene(object);
    
//    matSphere = ObjectMaterial(0, 0,0, Color(10,200,10));
//    object = new SphereObject(0.2f, glm::vec3(0.5, -0.8, -4), matSphere, glm::vec3(0,0,0));
//    room->addObjectToScene(object);

    //Add cube to scene
//    ObjectMaterial matCube = ObjectMaterial(0, 0.2, Color(100, 50, 50));
//    object = new CubeObject(glm::vec3(1, -0.75, -4.5), 0.5, 0.5, 0.5, matCube, glm::vec3(0,0,1));
//    room->addObjectToScene(object);


    //Add walls to room
    ObjectMaterial mat = ObjectMaterial(0, 0, 0, Color(20, 100, 0));
    object = new PlaneObject(glm::vec3(-1.5, 0, -4), 0, 2, 3, mat, glm::vec3(1,0,0));
    room->addObjectToScene(object);

    mat = ObjectMaterial(0, 0, 0, Color(100, 0, 0));
    object = new PlaneObject(glm::vec3(1.5, 0, -4), 0, 2, 3, mat, glm::vec3(-1,0,0));
    room->addObjectToScene(object);

    mat = ObjectMaterial(0, 0, 0, Color(50, 50, 50));
    object = new PlaneObject(glm::vec3(0, 0, -5.5), 3, 2, 0, mat, glm::vec3(0,0,1));
    room->addObjectToScene(object);

    //Add floor and roof
    object = new PlaneObject(glm::vec3(0, -1, -4), 3, 0, 3, mat, glm::vec3(0,1,0));
    room->addObjectToScene(object);

    object = new PlaneObject(glm::vec3(0, 1, -4), 3, 0, 3, mat, glm::vec3(0,-1,0));
    room->addObjectToScene(object);


    //Add lightsource to scene
    matSphere = ObjectMaterial(0, 0,0, Color(250,250,250));
    SceneObject *light = new SphereObject(0.1, glm::vec3(0, 0.8, -4), matSphere, glm::vec3(0,0,0));
    room->addLightsourceToScene(light);


    //send rays from camera out to scene and save as pnm image
    camera->sendRaysThroughScene(room);
    
    final=clock()-init;
    int totSec = final / CLOCKS_PER_SEC;
    int min = totSec/60;
    double sec = totSec%60;
    
    std::cout << "Rendering time: " << min << "min, " << sec << "seconds " << std::endl;
    
    
    

    return 0;
}
