#ifndef FUSION_H
#define FUSION_H

class fusion
{
private:
    float radius1;
    float radius2;
    float distance;
    float pi;
public:
    fusion();
    fusion(float R1, float R2, float d);
    float InsideSectorTriangleArea(float radius, float triangleHeight);
    float SectorMinuTriangle();
    float CompactionRatio();
};

#endif // FUSION_H
