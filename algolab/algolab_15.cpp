#include <iostream>
#include <fstream>
#include<cmath>

using namespace std;

int main(){

	ifstream infile;
	infile.open("input.txt");

    int numTestCases;

	infile >> numTestCases;

	for (int i = 0; i < numTestCases; i++){
        int a, cnt;
        unsigned int ans;

        infile >> a;

        ans = a;
        cnt = 0;

        while (a != 0){
            if (a % 2 == 1) {
                cnt += 1;
            }
            a /= 2;
        }

        if ( cnt % 2 == 1) {
            ans += pow(2, 31);
        }

        cout << ans << endl;
	}

	infile.close();

	return -1;
}
