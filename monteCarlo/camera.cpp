//
//  camera.cpp
//  monteCarlo
//
//  Created by Daniel Holst on 2015-09-28.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#include "camera.h"

Camera::Camera(float width, float height)
{
    pos = glm::vec3(0,0,0);
    upDir = glm::vec3(0,1,0);
    dir = glm::vec3(0,0,-1);
    
    fovX = glm::pi<float>()/4;
    fovY = fovX * height / width;
    
    outputImage = new SceneImage(width, height);
}

//get new direction after intersection
glm::vec3 getNewDirection(IntersectionPoint* point, Ray& r)
{
    glm::vec3 newDir;
    
    r.setImportance(r.getImportance() * point->getMaterial().getSpecular());

    
//    std:: cout << "old dir: " << r.getDir().x <<":" << r.getDir().y << ":" << r.getDir().z << std::endl;
    newDir = r.getDir() - glm::vec3(2,2,2) * ( glm::dot(r.getDir(), point->getNormal()) * point->getNormal());
//     std:: cout << "new dir: " << newDir.x <<":" << newDir.y << ":" << newDir.z << std::endl;
    return newDir;
}

void Camera::sendShadowRays(TheRoom *room, IntersectionPoint *point)
{
    glm::vec3 dir;
    int nrOfLights = room->lightSources->size();
    int nrOfObjects = room->sceneObjects->size();
    float distToLight;
    float intensity;
    Color c;
    
    //loop through all light sources
    for( int i = 0; i < nrOfLights; i++)
    {
        //get direction to light source
        dir = room->lightSources->at(i)->getPos() - point->getPos();
        distToLight = glm::length(dir);
        
        //create shadow ray towards light source
        Ray shadowRay = Ray(point->getPos(), dir);
        bool hit = false;
        
        IntersectionPoint *tempPoint = point;
        glm::vec3 rayPos;
        glm::vec3 step = glm::vec3(0.01,0.01,0.01);
        
        //loop through all objects in scene and check if they are in the way
        for( int j = 0; j < 3; j++)
        {
            rayPos = shadowRay.getStart();
            
            for(int i = 0; i < 400; i++)
            {
                rayPos += shadowRay.getDir()*step;
                
                //if there is a object in the way
                if( room->sceneObjects->at(j)->intersection(rayPos) != nullptr )
                {
                    hit = true;
                    c = Color(point->getMaterial().getColor() * 0.1);
                    point->setMaterial(c);
                    break;
                }
            }
        }
        
        //if the point is directly illuminated by the lightsource
        if(!hit)
        {
            float dotProduct = glm::dot(tempPoint->getNormal(), shadowRay.getDir());
//            std::cout << dotProduct << std::endl;
            intensity = 0.15 * dotProduct * (1/std::log(distToLight* 300));
            if(intensity < 0)
            {
//                std::cout << intensity << std::endl;
                intensity = 0;
            }
            c = Color ( tempPoint->getMaterial().getColor() * room->lightSources->at(i)->getColor() * intensity );
//            c.print();
            tempPoint->setMaterial(c);
        }
    }
}

void Camera::sendRaysThroughScene(TheRoom *room)
{
    int width = outputImage->getWidth();
    int height = outputImage->getHeight();
    
    float imageX;
    float imageY;
    float imageZ = -1.0f;
    
    Ray ray;
    IntersectionPoint *point = nullptr;
    bool rayHit = false;
    int endOfRay = 0;
    
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
            glm::vec3 step = glm::vec3(0.01, 0.01, 0.01);
            
            glm::vec3 rayPos;
            rayHit = false;
            
            while ( endOfRay < 2 )
            {
                rayPos = ray.getStart();
                rayHit = false;
                
                for (int k = 0; k < 650; k++)
                {
                    rayPos += ray.getDir()*step;
                    
                    //loop through objects in scene and check for intersection
                    for(int i = 0; i < room->sceneObjects->size(); i++)
                    {
                        point = room->sceneObjects->at(i)->intersection(rayPos);
                        if(point != nullptr)
                        {
                            sendShadowRays(room, point);
                            
                            outputImage->setPixelValue(x ,y , Color(ray.getImportance(), ray.getImportance(), ray.getImportance()) * point->getMaterial().getColor());
//                            std::cout << "imp = " << ray.getImportance() << std::endl;
                            
                            //get new pos and dir of ray
                            ray.setDir(getNewDirection(point, ray));
                            ray.setStart(rayPos);
                            
                            rayHit = true;
                            
                        }
                        else
                        {
                            //if no object was hit
                            outputImage->setPixelValue(x ,y , Color(0, 0, 0));
                        }
                    }
                    if(rayHit)
                        break;
                }
                
            endOfRay++;
        //            endOfRay = monteCarlo(point);
                
                
            }
            endOfRay = 0;
            
            if(y%100 == 0 && x == 0)
            {
                std::cout << y/100 << "/" << height/100 << " rendered" << std::endl;
            }
            
            
        }
    }
    
    outputImage->saveImage("test.pnm");
}