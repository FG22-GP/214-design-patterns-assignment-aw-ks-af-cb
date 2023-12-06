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

float float2::DotProduct(const float2& v1, const float2& v2)
{
    return v1.X * v2.X + v1.Y * v2.Y;
}

float float2::AngleBetweenNormalized(const float2& v1, const float2& v2)
{
    float dotProduct = DotProduct(v1, v2);
    float magnitude1 = Magnitude(v1);
    float magnitude2 = Magnitude(v1);
    
    // Ensure denominators are not zero
    if (magnitude1 == 0.0f || magnitude2 == 0.0f) {
        // Handle the case where one of the vectors has zero magnitude.
        // You might want to return a default value or throw an exception.
        // Here, I'm just returning 0 degrees.
        return 0.0f;
    }
    
    // Calculate the cosine of the angle using the dot product and magnitudes
    float cosAngle = dotProduct / (magnitude1 * magnitude2);
    
    // Use arccos to get the angle in radians, then convert to degrees
    float angleRadians = std::acos(std::max(-1.0f, std::min(1.0f, cosAngle)));
    float angleDegrees = angleRadians * (180.0f / 3.14159265358979323846f);
    
    return angleDegrees;
}


float2 float2::Normalize()
{
    float magnitude = Magnitude();

    if (magnitude != 0.0f) {
        return {X / magnitude, Y / magnitude};
    } else {
        // Handle the case where the vector has zero magnitude.
        // You might want to return a default value or throw an exception.
        // Here, I'm just returning the original vector.
        return {0,0};
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


