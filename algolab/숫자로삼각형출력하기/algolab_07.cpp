#include <iostream>

using namespace std;

int main(){
	int numTestCases;

	cin >> numTestCases;

    int TriSize;

	for (int i = 0; i < numTestCases; i++){
		cin  >> TriSize;

        int col = 0;
        int d = 0;

        for (int i = 1; i <= TriSize; i++){
            cout << i << " ";
            col = i;

            for (int j = 1; j < i; j++){
                col += d;
                cout << col << " ";
                d--;
            }

            d = TriSize - 1;
            cout << endl;
        }
	}

    return -1;
}