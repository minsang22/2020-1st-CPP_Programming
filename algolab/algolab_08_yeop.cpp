#include <iostream>

using namespace std;

int main(){
	int numtestcase, size;

	cin >> numtestcase;
	for (int i = 0; i < numtestcase; i++) {
		cin >> size;
		for (int k = 1; k < size + 1; k++) { 
			if (k % 2 == 1) {
				cout << "*";
			}
			else {
				cout << "+";
			}
		}
		cout << endl;
        
		int j = 1;

		int half = size / 2 - 1;

		for (int b = size - 2; b > 0; b = b - 2) {
			for (int a = 0; a < j; a++) {
				cout << "-";
			}
			int count = b;
			while (count > 0) {
				if (count % 2 == 1) {
					cout << "*";
				}
				else {
					cout << "+";
				}
				count--;
			}
			for (int a = 0; a < j; a++) {
				cout << "-";
			}
			j++;
			cout << endl;
		}

		for (int b = 3; b < size - 1; b = b + 2) {
			for (int a = 0; a < half; a++) {
				cout << "-";
			}
			int count = b;
			while (count > 0) {
				if (count % 2 == 1) {
					cout << "*";
				}
				else {
					cout << "+";
				}
				count--;
			}
			for (int a = 0; a < half; a++) {
				cout << "-";
			}
			half--;
			cout << endl;
		}

		for (int k = 1; k < size + 1; k++) {
			if (k % 2 == 1) {
				cout << "*";
			}
			else {
				cout << "+";
			}
		}
		cout << endl;
	}
	return -1;
}