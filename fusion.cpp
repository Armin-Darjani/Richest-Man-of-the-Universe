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

//----calculates the rectangle area wich is inside the intended sector
void fusion::InsideSectorTriangleArea(){
    float halfBase;
    insideTrianglesHeight[0] = (distance*distance - radius2*radius2+radius1*radius1)/(2*distance); //formula 1 in fusion documentation for first virus
    insideTrianglesHeight[1] = (distance*distance - radius1*radius1+radius2*radius2)/(2*distance); //formula 1 in fusion documentation for second virus
    halfBase = sqrt((radius1*radius1)-(insideTrianglesHeight[0]*insideTrianglesHeight[0])); // calculates y in documentation
    insideTrianglesareas[0] = halfBase * insideTrianglesHeight[0];
    insideTrianglesareas[1] = halfBase * insideTrianglesHeight[1];

}

//----claculates the segments area(A1 and A2) using formulas 2, 3 and 4 of fusion
void fusion::SectorMinuTriangle(){
    float Teta1,Teta2;
    InsideSectorTriangleArea();
    Teta1 = acos(insideTrianglesHeight[0]/radius1)*180/pi;
    Teta2 = acos(insideTrianglesHeight[1]/radius2)*180/pi;
    cout << Teta1 << "    " << Teta2 << endl;
    segmentAreas[0] = ((Teta1*2*pi*radius1*radius1)/360) - insideTrianglesareas[0];
    segmentAreas[1] = ((Teta2*2*pi*radius2*radius2)/360) - insideTrianglesareas[1];

}

float fusion::CompactionRatio(){
    float compact_ratio;
   if(distance >= (radius1 + radius2)){
        compact_ratio = 1.0000;
    }
    else{
      SectorMinuTriangle();
      float area1 , area2;
      area1 = radius1*radius1*pi;
      area2 = radius2*radius2*pi;
      compact_ratio = (area1 + area2 - segmentAreas[0]-segmentAreas[1])/(area1+area2);
      }

    return compact_ratio;
}
