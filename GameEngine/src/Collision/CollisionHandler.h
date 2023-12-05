#pragma once

#include "../Struct/float2.h"

class CollisionHandler
{
    
public:
    static int DistanceSquared(float2 PositionA, float2 PositionB)
    {
        int deltaX = PositionB.X - PositionA.X;
        int deltaY = PositionB.Y - PositionA.Y;
        return (deltaX * deltaX) + (deltaY * deltaY);
    }
    
    static bool Collided(float2 PositionA, int RadiusA, float2 PositionB, int RadiusB)
    {
        const int DistaneSquared = DistanceSquared(PositionA, PositionB);
        const int RadiiSum = RadiusA + RadiusB;
        
        return DistaneSquared <= (RadiiSum * RadiiSum);
    }
};