#ifndef FUSION_H
#define FUSION_H

class fusion
{
private:
    float radius1;
    float radius2;
    float distance;
    float pi;
    float insideTrianglesHeight[2];
    float insideTrianglesareas[2];
    float segmentAreas[2];
public:

    void InsideSectorTriangleArea();
    void SectorMinuTriangle();
    fusion();
    fusion(float R1, float R2, float d);

    float CompactionRatio();
};

#endif // FUSION_H
