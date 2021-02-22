#include <iostream>
#include <string>

using namespace std;

int main(){
    int Numtestcase;
    cin >> Numtestcase;

    for(int i = 0; i < Numtestcase; i++){
        char answer[4];
        char guess[4];
        bool checkstrike[4] = {false, false, false, false};
        bool checkball[4] = {false, false, false, false};

        string a;
        string b;

        int strike = 0;
        int ball = 0;
        
        cin >> a >> b;

        for(int j = 0; j < 4; j++){
            answer[j] = a[j];
            guess[j] = b[j];
        }

        for(int j = 0; j < 4; j++){
            if(answer[j] == guess[j]){
                strike += 1;
                checkstrike[j] = true;
            }
        }

        for(int j = 0; j < 4; j++){
            for(int z = 0; z < 4; z++){
                if((answer[j] == guess[z]) && (checkstrike[j] != true) && (checkstrike[z] != true)){
                    ball += 1;
                }
            }
        }

        if( (checkstrike[0] == true) && (checkstrike[1] == true) && (checkstrike[2] == true) && (checkstrike[3] == true)){
            cout << "4" << " " << "4" << endl;
        }
        else{
            cout << strike << " " << ball << endl;
        }
        
        
        
    }

    return -1;

}