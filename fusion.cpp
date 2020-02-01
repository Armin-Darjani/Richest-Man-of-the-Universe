#include "fusion.h"
#include <cmath>
#include <iostream>
using namespace std;
fusion::fusion()
{
}
fusion::fusion(float R1, float R2, float d){
    this->radius1 = R1;
    this->radius2 = R2;
    this->distance = d;
    this->pi = 3.14;
}

float fusion::InsideSectorTriangleArea(float radius, float triangleHeight){
    float triangleBase;
    triangleBase = sqrt(radius*radius - triangleHeight*triangleHeight);

    return triangleBase*triangleHeight;// triangleBase*2*1/2*height

}

float fusion::SectorMinuTriangle(){
    float triangleHeight, insideTriangleArea, sectorArea, teta, segment_area;
    triangleHeight = radius2 -(radius2 -(distance-radius1))/2;
    insideTriangleArea = InsideSectorTriangleArea(radius2 , triangleHeight);
    teta = acos(triangleHeight/radius2)*180/pi;
    sectorArea = (2*teta*pi/360) * radius2 * radius2;
    segment_area = sectorArea - insideTriangleArea;
    return segment_area;

}

float fusion::CompactionRatio(){
    float compact_ratio;
    if(distance >= (radius1 + radius2)){
        compact_ratio = 1.0000;
    }
    else{
      float segment_area, area1 , area2;
      segment_area = SectorMinuTriangle();
      area1 = radius1*radius1*pi;
      area2 = radius2*radius2*pi;
      compact_ratio = (area1 + area2 - 2*segment_area)/(area1+area2);
      }
    return compact_ratio;
}
