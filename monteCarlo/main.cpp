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


const int screenWidth = 800;
const int screenHeight = 600;

int main(int argc, char** argv)
{
    //init enviroment and camera
    TheRoom *Room = new TheRoom();
    Camera *camera = new Camera();
    
    camera->sendRaysThroughScene();
    
    return 0;
}