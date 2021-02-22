#include <iostream>
using namespace std;


int main() {
	int numtestcase;
	int size;
	char array[100][100];
	cin >> numtestcase;

	for (int k = 0; k < numtestcase; k++) {

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				array[i][j] = '.';
			}
		}

		cin >> size;
		int kk = (size - 1) / 2;

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (kk == i) {
					array[i][j] = '+';
				}
				if (kk == j) {
					array[i][j] = 'I';
				}
				if (i + j == size - 1) {
					array[i][j] = '*';
				}

			}
		}

		array[kk][kk] = 'O';
        
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << array[i][j];
			}
			cout << endl;
		}
	}
	return -1;
}