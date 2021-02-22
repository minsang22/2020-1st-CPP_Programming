#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int numTestCases;
    cin >> numTestCases;

    for(int i= 0; i < numTestCases; i++){
        int x1, x2, x3, y1, y2, y3;
        double a, b, c; 
        
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        
        double arr1[3];
        double arr2[3];

        arr1[0] = sqrt( pow(x2-x1,2) + pow(y2-y1,2) );
        arr1[1] = sqrt( pow(x3-x2,2) + pow(y3-y2,2) );
        arr1[2] = sqrt( pow(x3-x1,2) + pow(y3-y1,2) );

        arr2[0] = pow(x2-x1,2) + pow(y2-y1,2);
        arr2[1] = pow(x3-x2,2) + pow(y3-y2,2);
        arr2[2] = pow(x3-x1,2) + pow(y3-y1,2);

        sort(arr1, arr1+3);
        sort(arr2, arr2+3);

        if(arr1[0] + arr1[1] > arr1[2]){
            if (arr2[0] + arr2[1] == arr2[2]){
                cout << 1 << endl;
                }
                
            else if (arr2[0] + arr2[1] < arr2[2]){
                cout << 2 << endl;
                }

            else if (arr2[0] + arr2[1] > arr2[2]){
                cout << 3 << endl;
                }
        }
        
        else{
            cout << 0 << endl;
        }
    }
    
    return -1;
}