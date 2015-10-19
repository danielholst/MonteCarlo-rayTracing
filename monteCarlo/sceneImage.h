//
//  sceneImage.h
//  monteCarlo
//
//  Created by Daniel Holst on 2015-10-05.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#ifndef __monteCarlo__sceneImage__
#define __monteCarlo__sceneImage__

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cmath>
#include "color.h"

class SceneImage
{
public:
    SceneImage(int width, int height);
    
    void saveImage(const char *filename);
    void setPixelValue(int x, int y, Color c);
    int getHeight();
    int getWidth();
    
private:
    int imgHeight;
    int imgWidth;
    
    float *pixelValues;
    
};

#endif /* defined(__monteCarlo__sceneImage__) */
