#include <iostream>

using namespace std;

int main(){
    int numTestCases;
    cin >> numTestCases;

    for(int i= 0; i < numTestCases; i++){
        int r, s, t;
        int a[100][100], b[100][100], c[100][100];
        int sum = 0;

        cin >> r >> s >> t;

        for(int j = 0; j < r; j++){
            for(int k = 0; k < s; k++){
                cin >> a[j][k];
            }
        }
        
        for(int j = 0; j < s; j++){
            for(int k = 0; k < t; k++){
                cin >> b[j][k];
            }
        }

        for(int j = 0; j < r; j++){
            for(int k = 0; k < t; k++){
                sum = 0;
                for(int z = 0; z < s; z++){
                    sum += a[j][z] * b[z][k];
                }
                c[j][k] = sum;
            }
        }

        for(int j = 0; j < r; j++){
            for(int k = 0; k < t; k++){
                cout << c[j][k] << " ";
            }
            cout << endl;
        }
    }
    
    return -1;
}