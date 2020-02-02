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

    float exponentialRadiusOfEachChild , maxDistance, radiusOfEachChild;
    exponentialRadiusOfEachChild = (vRadius*vRadius)/2;
    radiusOfEachChild = sqrt(exponentialRadiusOfEachChild);
    maxDistance = sqrt((recLength - 2*radiusOfEachChild)*(recLength - 2*radiusOfEachChild) + (recWidth - 2*radiusOfEachChild)*(recWidth - 2*radiusOfEachChild));

    if( 4*radiusOfEachChild > recLength) // the rectangle cannot contain both circles
        return -1;
    else if(2*radiusOfEachChild > recWidth)// the rectangle cannot contain both circles
        return -1;
    else
        return maxDistance;
}
