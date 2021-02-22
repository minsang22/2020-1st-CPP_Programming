#include <iostream>

using namespace std;

int main(){
    int numTestCases; 
    cin >> numTestCases;
    for(int i =0; i < numTestCases; i++){
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> x3 >> y3 >> x4 >> y4;
        if (x1 == x2){
            if ((min(x3, x4) < x1 && max(x3, x4) > x1) &&
                    (min(y1, y2) < y3 && max(y1, y2) > y3))
            {
                cout << 1 << endl;
            }
            else if ((max(x3, x4) < x1 || min(x3, x4) > x1) ||
                    (y3 > max(y1, y2) || y3 < min(y1, y2)))
            {
                cout << 0 << endl;
            }
            else
            {
                cout << 2 << endl;
            }
        }
        else if(y1 == y2){
            if ((min(y3, y4) < y1 && max(y3, y4) > y1) &&
                    (min(x1, x2) < x3 && max(x1, x2) > x3))
            {
                cout << 1 << endl;
            }
            else if ((max(y3, y4) < y1 || min(y3, y4) > y1) ||
                    (x3 > max(x1, x2) || x3 < min(x1, x2)))
            {
                cout << 0 << endl;
            }
            else
            {
                cout << 2 << endl;
            }
        }
    }
}