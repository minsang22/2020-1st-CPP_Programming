#include <iostream>

using namespace std;

int main(){
    int numTestCases;
    cin >> numTestCases;

    for(int i= 0; i < numTestCases; i++){
        int a[100][100], b[100][100], c[100][100];
        int row, col;

        cin >> row >> col;

        for(int j = 0; j < row; j++){
            for (int k = 0; k < col; k++) {
                cin >> a[j][k];
            }
        }

        for(int j = 0; j < row; j++){
            for (int k = 0; k < col; k++) {
                cin >> b[j][k];
            }
        }

        for(int j = 0; j < row; j++){
            for (int k = 0; k < col; k++) {
                c[j][k] = a[j][k] + b[j][k];
            }
        }

        for(int j = 0; j < row; j++){
            for (int k = 0; k < col; k++) {
                cout << c[j][k] << " "; 
            }
            cout << endl;
        }

    }
    
    return -1;
}