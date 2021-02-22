#include <iostream>

using namespace std;

int answer(int a, int b, int c);

int main(){
    int numTestCases;
    cin >> numTestCases;

    int a, b, c;

    for(int i= 0; i < numTestCases; i++){
        cin >> a >> b >> c;
        cout << answer(a, b, c) << endl;
    }
    
    return -1;
}


int answer(int a, int b, int c){
    if( a + b <= c){
        return 0;
    }
    
    else if( a == b && b == c){
        return 1;
    }

    else if( a*a + b*b == c*c){
        return 2;
    }

    else if( a == b || b == c){
        return 3;
    }

    else{
        return 4;
    }
}