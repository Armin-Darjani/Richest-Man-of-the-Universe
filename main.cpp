#include <iostream>;
#include "fission.h";
#include "fusion.h";
#include <cmath>
#include <stdio.h>
#include <fstream>
#include "string.h"
using namespace std;

struct userInput{
    char fissionOrFusion;
    float L_R1;
    float W_R2;
    float R_d;
};

int main(int argc, char *argv[])
{

    bool numOflines = false;
    userInput *user_input;
// for reading from a file
    ifstream myReadFile;
    int num_of_lines;
    int counter = 0;
    myReadFile.open("C:/Users/Armin/Desktop/text.txt");
    int output;
    if (myReadFile.is_open()) {
         while (!myReadFile.eof()) {
             if(numOflines == false){
                numOflines = true;
                myReadFile >> num_of_lines;
                cout << num_of_lines<<endl;
                user_input = new userInput[num_of_lines];
            }
             else{
               myReadFile >> user_input[counter].fissionOrFusion >> user_input[counter].L_R1 >> user_input[counter].W_R2 >> user_input[counter].R_d;
              // cout << user_input[counter].fissionOrFusion << user_input[counter].L_R1 << user_input[counter].W_R2 << user_input[counter].R_d<< endl;
               counter = counter + 1;
             }
         }
    }
//------
    fission *fissionOperation;
    fusion  *fusinOperation;
    float outFission;
    float outFusion;
    for(int i = 0 ; i < num_of_lines ; i++ ){
        if(user_input[i].fissionOrFusion == 'S'){
            fissionOperation = new fission(user_input[i].L_R1 , user_input[i].W_R2 ,user_input[i].R_d);
            outFission = fissionOperation->MaxDistance();
            if(outFission == -1)
                cout << "Not enough space for fission."<<endl << endl;
            else
                cout << outFission << endl<<endl;
            delete fissionOperation;
        }
        else if(user_input[i].fissionOrFusion == 'M'){
            fusinOperation = new fusion(user_input[i].L_R1 , user_input[i].W_R2 ,user_input[i].R_d);
            outFusion = fusinOperation->CompactionRatio();
            if(outFusion == 1.0000)
                printf("%.4f \nNo compaction has occured.\n" , outFusion);
            else
                cout << outFusion << endl<<endl;
            delete fusinOperation;
        }
        else
            continue;
    }
    while(1){};

    return 0;
}
