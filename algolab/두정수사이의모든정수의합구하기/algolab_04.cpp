#include <iostream>

using namespace std;

int main(){
    int numTestCases;
    cin >> numTestCases;

    for(int i= 0; i < numTestCases; i++){
        int sum = 0;
        int start, end;

        cin >> start;
        cin >> end;

        for(int j = start; j < end+1; j++){
            sum += j;
        }
        
        cout << sum << endl;
    }
    
    return -1;
}