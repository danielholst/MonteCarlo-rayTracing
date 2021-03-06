//
//  objectMaterial.cpp
//  monteCarlo
//
//  Created by Daniel Holst on 2015-10-14.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#include "objectMaterial.h"

ObjectMaterial::ObjectMaterial()
{
    diffuse = 0;
    transparance = 0;
    specular = 0;
    color = Color(0,0,0);
}

ObjectMaterial::ObjectMaterial(float diff, float transp, float spec, Color c, bool light)
{
    diffuse = diff;
    transparance = transp;
    specular = spec;
    color = c;
    isLightSource = light;
}

bool ObjectMaterial::checkSpecular()
{
    if(specular != 0)
        return true;
    else
        return false;
}

bool ObjectMaterial::checkTransparace()
{
    if(transparance != 0)
        return true;
    else
        return false;
}

Color ObjectMaterial::getColor()
{
    return color;
}

void ObjectMaterial::setColor(Color c)
{
    color = c;
}

float ObjectMaterial::getDiffuse()
{
    return diffuse;
}

float ObjectMaterial::getTransparance()
{
    return transparance;
}

float ObjectMaterial::getSpecular()
{
    return specular;
}