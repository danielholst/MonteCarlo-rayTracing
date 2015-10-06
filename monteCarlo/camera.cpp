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
    upDir = glm::vec3(0,1,0);
    dir = glm::vec3(0,0,-1);
    
    fovX = glm::pi<float>()/4;
    fovY = fovX * 600 / 800;
    
    outputImage = new SceneImage(800, 600);
}

void Camera::sendRaysThroughScene()
{
    int width = outputImage->getWidth();
    int height = outputImage->getHeight();
    
    float imageX;
    float imageY;
    float imageZ = -1.0f;
    
    Ray ray;
    
    std::cout << width << " " << height << std::endl;
    //loop through all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //map world coordinates to image plane
            outputImage->setPixelValue(j ,i , 244, 0, 0);
            
            
        }
    }
    
    outputImage->saveImage("test.pnm");
}