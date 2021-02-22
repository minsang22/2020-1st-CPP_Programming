#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int numTestCases;

	ifstream infile;
    infile.open("input.txt");

    infile >> numTestCases;

    for(int i= 0; i < numTestCases; i++){
        int num;
        int cnt = 0;

        infile >> num;

        for(int i = 1; i <= num; i++){
            if (num % i == 0){
                cnt += 1;
            }
        }

        if (cnt == 2){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }

	infile.close();

	return -1;
}