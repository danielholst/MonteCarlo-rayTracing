//
//  color.h
//  monteCarlo
//
//  Created by Daniel Holst on 2015-10-14.
//  Copyright (c) 2015 Daniel Holst. All rights reserved.
//

#ifndef __monteCarlo__color__
#define __monteCarlo__color__

#include <stdio.h>

class Color
{
public:
    Color();
    Color(float rC, float gC, float bC);
    
private:
    float r;
    float g;
    float b;
};
#endif /* defined(__monteCarlo__color__) */
