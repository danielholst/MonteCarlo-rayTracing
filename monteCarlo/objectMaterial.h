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

class ObjectMaterial
{
public:
    
    ObjectMaterial();
    ObjectMaterial(float transp, float spec, Color c);
    
    bool checkTransparace();
    bool checkSpecular();
    
    Color getColor();
    
    float getTransparance();
    float getSpecular();
    
private:
    
    float specular;
    float transparance;
    Color color;
};

#endif /* defined(__monteCarlo__objectMaterial__) */
