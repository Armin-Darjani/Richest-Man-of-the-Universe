#ifndef FISSION_H
#define FISSION_H
class fission
{

private:
    float recLength;
    float recWidth;
    float vRadius;

public:
    fission();
    fission(float l ,float w ,float r);
    float MaxDistance();
};

#endif // FISSION_H
