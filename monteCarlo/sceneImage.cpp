//
//  sceneImage.cpp
//  monteCarlo
//
//  Created by Daniel Holst on 2015-10-05.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#include "sceneImage.h"


SceneImage::SceneImage(int width, int height)
{
    //Standard size
    imgHeight = height;
    imgWidth = width;
    
    pixelValues = new float [ imgHeight * imgWidth * 3 ];
}

int SceneImage::getHeight()
{
    return imgHeight;
}

int SceneImage::getWidth()
{
    return imgWidth;
}

void SceneImage::setPixelValue(int x, int y, float r, float g, float b)
{
    pixelValues[(x + y*imgWidth) *3] = r;
    pixelValues[(x + y*imgWidth) *3 + 1] = g;
    pixelValues[(x + y*imgWidth) *3 + 2] = b;
}

void SceneImage::saveImage(const char *filename)
{
    std::ofstream stream(filename);
    
    if(!stream.is_open())
    {
        std::cout << "Couldn't open file" << std::endl;
    }
    
    //header for a pnm file
    stream << "P3 " << imgWidth << " " << imgHeight << " 255 \n";
    
    //header for pmm file
//    stream << "P6 " << imgWidth << " " << imgHeight << " 255 \n";
    
//    float *pixel = pixelValues;
    for (int j = 0; j < imgHeight; ++j) {
        for (int i = 0; i < imgWidth; ++i) {
            int r = pixelValues[(i + j*imgWidth) * 3];
            int g = pixelValues[(i + j*imgWidth) * 3 + 1];
            int b = pixelValues[(i + j*imgWidth) * 3 + 2];
            
//            unsigned char r = (unsigned char)(std::max(0.f, std::min(255.f, powf(pixel[0], 1/2.2) * 255 + 0.5f)));
//            unsigned char g = (unsigned char)(std::max(0.f, std::min(255.f, powf(pixel[1], 1/2.2) * 255 + 0.5f)));
//            unsigned char b = (unsigned char)(std::max(0.f, std::min(255.f, powf(pixel[2], 1/2.2) * 255 + 0.5f)));
            if(r > 255)
                r = 255;
            if(g > 255)
                g = 255;
            if(b > 255)
                b = 255;
            
            if(i != imgWidth-1)
                stream << r << "  "<< g << "  " << b << "    ";
            else
                stream << r << "  " << g << "  " << b;
//            pixel += 3;
        }
        stream << "\n";
    }
    stream.close();
    
    std::cout << "To image" << std::endl;
    
    
}