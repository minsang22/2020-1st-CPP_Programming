#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int numTestCases;
    cin >> numTestCases;

    for(int i= 0; i < numTestCases; i++){
        int numData;
        int a = 0;
        int b = 0;
        int x1 = 0;
        int y1 = 0;
        int x2, y2;
        int ans = 0;
        int c, d;
        
        cin >> numData;

        cin >> x1 >> y1;
        
        c = x1;
        d = y1;
        
        for(int j = 0; j < numData-1; j++){
            cin >> x2 >> y2;

            a = x1 + x2;
            b = y2 - y1;

            ans += a*b;

            x1 = x2;
            y1 = y2;
        }

        ans += (x2 + c)*(d-y2);
        
        if(ans > 0){
            cout << ans << " " << 1 << endl;
        }

        else{
            cout << abs(ans) << " " << -1 << endl;
        }
    }
    
    return -1;
}