#include <iostream>

using namespace std;

int main(){
    int numTestCases;
    cin >> numTestCases;

    for(int i= 0; i < numTestCases; i++){
        int numData, data;
        int max;
        int min;

        cin >> numData;

        cin >> data;
        max = data;
        min = data;

        for(int j = 1; j < numData; j++){
            cin >> data;
            if (max < data){
                max = data;
            }

            if (min > data){
                min = data;
            }
            
        }
        cout << max << " " << min <<  endl;
    }
    
    return -1;
}