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

//get diffuse reflection direction
glm::vec3 CosWeightedRandomHemisphereDirection2( glm::vec3 n )
{
    const int PI = 3.1415926535897932384626433832795;
    float Xi1 = (float)rand()/(float)RAND_MAX;
    float Xi2 = (float)rand()/(float)RAND_MAX;
    
    float  theta = acos(sqrt(1.0-Xi1));
    float  phi = 2.0 * PI * Xi2;
    
    float xs = sinf(theta) * cosf(phi);
    float ys = cosf(theta);
    float zs = sinf(theta) * sinf(phi);
    
    glm::vec3 y(n.x, n.y, n.z);
    glm::vec3 h = y;
    if (fabs(h.x)<=fabs(h.y) && fabs(h.x)<=fabs(h.z))
        h.x= 1.0;
    else if (fabs(h.y)<=fabs(h.x) && fabs(h.y)<=fabs(h.z))
        h.y= 1.0;
    else
        h.z= 1.0;
    
    
    glm::vec3 x = glm::normalize(pow(h,y));
    glm::vec3 z = glm::normalize(pow(x,y));
    
    glm::vec3 direction = xs * x + ys * y + zs * z;
    return glm::normalize(direction);
}
//get new direction after intersection
glm::vec3 getNewDirection(IntersectionPoint* point, Ray& r)
{
    glm::vec3 newDir;
    //    std:: cout << "old dir: " << r.getDir().x <<":" << r.getDir().y << ":" << r.getDir().z << std::endl;
    
    if ( point->getMaterial().checkSpecular() ) // if point is specular
    {
        r.setImportance(r.getImportance() * point->getMaterial().getSpecular());
        newDir = r.getDir() - glm::vec3(2,2,2) * ( glm::dot(r.getDir(), point->getNormal()) * point->getNormal());
    }
    else if( point->getMaterial().checkTransparace()) // if point is transparent
    {
        
    }
    else    //if point is diffuse
    {
        //generate random new dir
        r.setImportance(0.2);
        newDir = CosWeightedRandomHemisphereDirection2(point->getNormal());
        
    }

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
        
        IntersectionPoint *tempPoint = nullptr;

        //loop through all objects in scene and check if they are in the way
        for( int j = 0; j < nrOfObjects; j++)
        {
            tempPoint =  room->sceneObjects->at(j)->intersection2( shadowRay );
            if( tempPoint != nullptr && (glm::length(tempPoint->getPos() - point->getPos())) < distToLight)
                {
                    hit = true;
                    c = Color(point->getMaterial().getColor() * 0.2);
                    point->setMaterial(c);
                    break;
                }
        }
        
        //if the point is directly illuminated by the lightsource
        if(!hit)
        {
            float dotProduct = glm::dot(point->getNormal(), shadowRay.getDir());
            intensity = 0.15 * dotProduct * (1/std::log(distToLight* 300));
            
            if(intensity < 0)
            {
                intensity = 0;
            }
            c = Color ( point->getMaterial().getColor() * room->lightSources->at(i)->getColor() * intensity );
            point->setMaterial(c);
        }
    }
}


void Camera::sendRaysThroughScene(TheRoom *room)
{
    int width = outputImage->getWidth();
    int height = outputImage->getHeight();
    int nrOfSampleRays = 40;
    int endOfRay = 0;
    
    float imageX;
    float imageY;
    float imageZ = -1.0f;
    
    float diffX;
    float diffY;
    
    Ray ray;
    IntersectionPoint *point = nullptr;

    
    std::cout << "Size of image = [ "<< width << " : " << height <<" ]" << std::endl;

    //loop through all pixels
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            //rays per pixel
            for ( int i = 0 ; i< nrOfSampleRays; i++)
            {
                //random diff on ray through pixel
                diffX = (2*(float)(rand() % 100) / 100)/(2*width) - (0.5/(float)width);
                diffY = (float)(rand() % 100) / 100/(2*height) - (0.5/(float)height);
                
                
                //map world coordinates to image plane
                imageX = tan(fovX / 2) * (2 * x - width) / float(width) + diffX;
                imageY = tan(fovY / 2) * (height - 2 * y) / float(height) + diffY;
                
                //send rays through the pixel in the image plane out into the scene
                ray = Ray(pos, glm::vec3(imageX, imageY, imageZ));
                
                while ( endOfRay < 3 )
                {
                        IntersectionPoint* temp = nullptr;
                    
                        //loop through objects in scene and check for intersection
                        for(int i = 0; i < room->sceneObjects->size(); i++)
                        {

                            point = room->sceneObjects->at(i)->intersection2(ray);
                            if(point != nullptr)
                            {
                                temp = point;
                            }
                            else
                            {
                                //if no object was hit
                                outputImage->setPixelValue(x ,y , Color(0, 0, 0));
                            }
                        }
                        if(temp)
                        {
                            sendShadowRays(room, temp);
                            outputImage->setPixelValue(x ,y , temp->getMaterial().getColor() * (float)(ray.getImportance() * (1/(float)nrOfSampleRays)));
                            
                            //get new pos and dir of ray
                            ray.setDir(getNewDirection(temp, ray));
                            ray.setStart(temp->getPos());
                            ray.setMinDist(100);
                        }
                
                endOfRay++;
    //          endOfRay = monteCarlo(point);
                    
                }
                endOfRay = 0;
            
                if(y%100 == 0 && x == 0 && i == 0)
                {
                    std::cout << y/100 << "/" << height/100 << " rendered" << std::endl;
                }
            }
        
        }
    }
    
    outputImage->saveImage("test.pnm");
}