#include "fission.h"
#include <iostream>;
#include <cmath>;
using namespace std;
fission::fission()
{
    cout << "please use the other constructor"<<endl;
}
fission::fission(float l, float w, float r){
    this->recLength = l;
    this->recWidth = w;
    this->vRadius = r;
}
float fission::MaxDistance(){

    float exponentialRadiusOfEachChild , maxDistance, recDiameter, spaceChecker, radiusOfEachChild;
    exponentialRadiusOfEachChild = (vRadius*vRadius)/2;
    radiusOfEachChild = sqrt(exponentialRadiusOfEachChild);
    recDiameter = sqrt(recLength*recLength + recWidth*recWidth);
    maxDistance = recDiameter - 2*sqrt(2*exponentialRadiusOfEachChild);
    spaceChecker = maxDistance - 2*radiusOfEachChild;
    if(spaceChecker >= 0)
        return maxDistance;
    else
        return -1;
}
