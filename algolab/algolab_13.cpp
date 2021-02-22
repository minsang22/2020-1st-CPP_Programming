#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int numTestCases;
    cin >> numTestCases;

    for(int i= 0; i < numTestCases; i++){
        int ax, ay, bx, by, cx, cy;
        int area;
        int area2;

        cin >> ax >> ay >> bx >> by >> cx >> cy;

        area = ( ( (bx - ax) * (cy - ay) ) - ( (cx - ax) * (by - ay) ) );
        area2 = abs(area);


        if( area > 0 ){
            cout << area2 << " " << 1 << endl;
        }

        else if ( area < 0){
            cout << area2 << " " << -1 << endl;
        }

        else{
            cout << 0 << " " << 0 << endl;
        }
    }
    
    return -1;
}