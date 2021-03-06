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

void SceneImage::setPixelValue(int x, int y, Color c)
{
    pixelValues[(x + y*imgWidth) *3] += c.getR();
    pixelValues[(x + y*imgWidth) *3 + 1] += c.getG();
    pixelValues[(x + y*imgWidth) *3 + 2] += c.getB();
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
    
    for (int j = 0; j < imgHeight; ++j) {
        for (int i = 0; i < imgWidth; ++i) {
            int r = pixelValues[(i + j*imgWidth) * 3];
            int g = pixelValues[(i + j*imgWidth) * 3 + 1];
            int b = pixelValues[(i + j*imgWidth) * 3 + 2];

            //gamma correction
            r = pow(r, 1/2.2);
            g = pow(g, 1/2.2);
            b = pow(b, 1/2.2);
            
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
        }
        stream << "\n";
    }
    stream.close();
    
    std::cout << "Saved to: " << filename << std::endl;
    
    
}