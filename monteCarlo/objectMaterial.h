//
//  objectMaterial.h
//  monteCarlo
//
//  Created by Daniel Holst on 2015-10-14.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#ifndef __monteCarlo__objectMaterial__
#define __monteCarlo__objectMaterial__

#include <stdio.h>
#include "color.h"

// Class to handle material for object
class ObjectMaterial
{
public:
    
    ObjectMaterial();
    ObjectMaterial(float diffuse, float transp, float spec, Color c, bool light = false);
    
    bool checkTransparace();
    bool checkSpecular();
    
    Color getColor();
    void setColor(Color c);
    
    float getDiffuse();
    float getTransparance();
    float getSpecular();
    
private:
    
    bool isLightSource;
    float diffuse;
    float specular;
    float transparance;
    Color color;
};

#endif /* defined(__monteCarlo__objectMaterial__) */
