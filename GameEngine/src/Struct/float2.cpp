#include "float2.h"
#include <iostream>

float2::float2()
{
    this->X = 0;
    this->Y = 0;
}

float2::float2(float X, float y)
{
    this->X = X;
    this->Y = y;
}

float2 float2::Normalize()
{
    float len = Magnitude();
    
    if (len != 0.0f) {
        // Normalized vector
    
        float XNorm = X / len;    
        float YNorm = Y / len;

        std::cout << XNorm << " " << YNorm << std::endl;
        
        float2 returnValue = {XNorm, YNorm};
        return returnValue;
    } else {
        // Handling zero-length vector (avoid division by zero)
        return {0, 0};
    }
}

float float2::Magnitude()
{
    return std::sqrt(X * X + Y * Y);
}

float float2::Magnitude(float2 Vector)
{
    return std::sqrt(Vector.X * Vector.X + Vector.Y * Vector.Y);
}


