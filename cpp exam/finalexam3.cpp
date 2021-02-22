#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int Numtestcase;
    cin >> Numtestcase;

    for(int i = 0; i < Numtestcase; i++){
        char total[390] = {0};
        char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        int workNum[26];
        int sortworkNum[26];
        bool check[26] = {false};
        int cnt = 0;
        
        int caseNum;
        int checktime;
        cin >> caseNum >> checktime;

        for(int j = 0; j < caseNum; j++){
            cin >> workNum[j];
            sortworkNum[j] = workNum[j];
        }

        sort(sortworkNum, sortworkNum+caseNum);

        for(int j = 0; j < caseNum; j++){
            for(int z = 0; z < caseNum; z++){
                if((sortworkNum[j] == workNum[z]) && check[z] != true){
                    check[z] = true;
                    for(int k = 0; k < workNum[z]; k++){
                        total[cnt] = alphabet[z];
                        cnt += 1;
                    }
                }
            }   
        }
        
        if(total[checktime] == 0){
            cout << "-1" << endl;
        }
        else{
            cout << total[checktime] << endl;
        }
        
        
    }

    return -1;

}