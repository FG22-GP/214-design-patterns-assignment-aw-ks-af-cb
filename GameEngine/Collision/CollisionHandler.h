#pragma once

class CollisionHandler
{
    
public:
    static float DistanceSquared(float2 PositionA, float2 PositionB)
    {
        float deltaX = PositionB.x - PositionA.x;
        float deltaY = PositionB.y - PositionA.y;
        return (deltaX * deltaX) + (deltaY * deltaY);
    }
    
    static bool Collided(float2 PositionA, float RadiusA, float2 PositionB, float RadiusB)
    {
        const float DistaneSquared = DistanceSquared(PositionA, PositionB);
        const float RadiiSum = RadiusA + RadiusB;
        
        return DistaneSquared <= (RadiiSum * RadiiSum);
    }
};