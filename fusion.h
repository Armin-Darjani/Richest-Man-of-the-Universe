#ifndef FUSION_H
#define FUSION_H

class fusion
{
private:
    float radius1;
    float radius2;
    float distance;
    float pi;
    float InsideSectorTriangleArea(float radius, float triangleHeight);
    float SectorMinuTriangle();
public:
    fusion();
    fusion(float R1, float R2, float d);

    float CompactionRatio();
};

#endif // FUSION_H
