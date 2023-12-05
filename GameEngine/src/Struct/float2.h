#pragma once

struct float2
{
public:
    int X;
    int Y;

    float2();
    float2(int X, int y);

    float2 operator-(const float2 rhs)
    {
        return float2(X-rhs.X, Y-rhs.Y); 
    }
};
