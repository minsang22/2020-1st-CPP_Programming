#include <iostream>

using namespace std;

int main(){
    int numTestCases;
    int size;
     char graph[100][100];
    cin >> numTestCases;

    for(int i= 0; i < numTestCases; i++){
        cin >> size;

        int half = (size - 1)/2;

        for (int j = 0; j < size; j++){
            for (int z = 0; z < size; z++){
                graph[j][z] = '.';
            }
        }

        for (int j = 0; j < size; j++){
            for( int z = 0; z < size; z++){
                if(z == half) {
                    graph[j][z] = 'I';
                }
                
                if(j + z == size - 1){
                    graph[j][z] = '*';
                }

                if(j == half) {
                    graph[j][z] = '+';
                }
            }
        }

        graph[half][half] = '0';

        for (int j = 0; j < size; j++){
            for ( int z = 0; z < size; z++){
                cout << graph[j][z];
            }
            cout << endl;
        }
    }
    return -1;
}