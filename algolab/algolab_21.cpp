#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream infile;

    infile.open("input.txt");

    int numTestcases;

    infile >> numTestcases;

    for (int i = 0; i < numTestcases; i++){
        int num;
        int arr[256];
        int k;
        int average = 0;

        infile >> num;

        for(int j = 0; j < num; j++){
            infile >> arr[j];
        }
        infile >> k;
        
        cout << num - k + 1 << " ";

        for(int j = 0; j < num - k + 1; j++){
            for(int z = 0; z < k; z++){
                average += arr[j+z];
            }
            average /= k;
            cout << average << " ";
            average = 0;
        }
        cout << endl;
    }

    return -1;
}
	
