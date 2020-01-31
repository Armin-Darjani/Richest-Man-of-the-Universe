#include <iostream>;
#include "fission.h";
using namespace std;

struct userInput{
    char fissionOrFusion;
    float L_R1;
    float W_R2;
    float R_d;
};

int main(int argc, char *argv[])
{
    userInput *user_input;
    int inputLines;
    cin >> inputLines;
    user_input = new userInput[inputLines];
    for(int i = 0 ; i < inputLines ; i++ ){
        cin >> user_input[i].fissionOrFusion >> user_input[i].L_R1 >> user_input[i].W_R2 >> user_input[i].R_d;
    }
    fission *fissionOperation;
    float outFission;
    for(int i = 0 ; i < inputLines ; i++ ){
        if(user_input[i].fissionOrFusion == 'S'){
            fissionOperation = new fission(user_input[i].L_R1 , user_input[i].W_R2 ,user_input[i].R_d);
            outFission = fissionOperation->MaxDistance();
            if(outFission == -1)
                cout << "Not enough space for fission"<<endl << endl;
            else
                cout << outFission << endl<<endl;
            delete fissionOperation;
        }
    }

    while(1){};

    return 0;
}
