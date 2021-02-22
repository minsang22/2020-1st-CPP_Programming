#include <iostream>

using namespace std;

int main(){
    int numTestCases;
    cin >> numTestCases;

    for(int i= 0; i < numTestCases; i++){
        int numData, data;
        int product = 1;

        cin >> numData;

        for(int j = 0; j < numData; j++){
            cin >> data;
            data  %=  10;
            product *= data;
            product %= 10;
        }
        
        
        cout << product << endl;
    }
    
    return -1;
}