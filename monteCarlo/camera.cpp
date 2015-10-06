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
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            //map world coordinates to image plane
            imageX = tan(fovX / 2) * (2 * x - width) / float(width);
            imageY = tan(fovY / 2) * (height - 2 * y) / float(height);
            
            //send rays through the pixel in the image plane out into the scene
            ray = Ray(pos, glm::vec3(imageX, imageY, imageZ));
            
            if (ray.direction.x >= 0)
                outputImage->setPixelValue(x ,y , 0, 244, 0);
            if (ray.direction.x < 0)
                outputImage->setPixelValue(x ,y , 0, 0, 244);
            if (ray.direction.y > 0)
                outputImage->setPixelValue(x ,y , 244, 0, 0);

            
            
        }
    }
    
    outputImage->saveImage("test.pnm");
}