#pragma once
#include <string>

struct float2
{
public:
    float X;
    float Y;

    float2();
    float2(float X, float y);

    float2 operator-(const float2 rhs) const
    {
        return {X-rhs.X, Y-rhs.Y}; 
    }

    float2 operator+ (const float2 rhs) const
    {
        return {X+rhs.X, Y+rhs.Y};
    }

    float2 operator* (const float rhs) const
    {
        return {X*rhs, Y*rhs};
    }

    float2& operator+= (const float2 rhs)
    {
        X += rhs.X;
        Y += rhs.Y;
        return *this;
    }

    std::string ToString() const
    {
        return std::to_string(X) + " " + std::to_string(Y);
    }

    float2 Normalize();
    float Magnitude();
    static float Magnitude(float2 Vector);
};
