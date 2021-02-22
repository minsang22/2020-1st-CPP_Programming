#include <iostream>

using namespace std;

int main(){
    int Numtestcase;
    cin >> Numtestcase;

    for(int i = 0; i < Numtestcase; i++){
        int mat1[50][50];
        int mat2[50][50];
        int mat3[50][50];

        int col;
        int row;

        cin >> col >> row;

        for(int j = 0; j < col; j++){
            for(int z = 0; z < row; z++){
                cin >> mat1[j][z];
            }
        }

        for(int j = 0; j < col; j++){
            for(int z = 0; z < row; z++){
                cin >> mat2[j][z];
            }
        }

        for(int j = 0; j < col; j++){
            for(int z = 0; z < row; z++){
                mat3[j][z] = mat1[j][z] * mat2[j][z];
            }
        }

        for(int j = 0; j < col; j++){
            for(int z = 0; z < row; z++){
                cout << mat3[j][z] << " ";
            }
            cout << endl;
        }

    }

    return -1;

}