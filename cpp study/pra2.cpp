#include <iostream>

using namespace std;

int main(){
    int numTestCases;
    cin >> numTestCases;

    for(int i= 0; i < numTestCases; i++){
        int count = 0;
        int numData;

        cin >> numData;

        for(int j = 1; j < numData+1; j++){
            for(int z = 0; z < j+1; z++){
                cout << i
            }
            for(int k = numData-1; k > -1; k--){
                cout << k << endl;
            }
        }
    }
    
    return -1;
}
