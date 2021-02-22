#include <iostream>

using namespace std;

int main(){
    int numTestCases;
    cin >> numTestCases;

    for(int i= 0; i < numTestCases; i++){
        int Y;
        cin >> Y;
        //cout << Y << endl;

        int C = Y/100;
        //cout << C << endl;

        int N = (Y - ((Y/19) * 19));
        //cout << N << endl;

        int T = ((C - 17)/25);
        //cout << T << endl;

        int q_5 = (C - (C/4) - ((C-T)/3)); 
        //cout << q_5 << endl;

        int q_6 = ((N*19) + 15);
        //cout << q_6 << endl;

        int I = (q_5 + q_6);
        //cout << I << endl;

        int J = (I - ((I/30)*30));
        //cout << J << endl;

        int q_9 = J/28;
        //cout << q_9 << endl;

        int q_10 = (1 - q_9);
        //cout << q_10 << endl;

        int q_11 = (29/(J+1));
        //cout << q_11 << endl;

        int q_12 = ((21-N)/11);
        //cout << q_12 << endl;

        int K = (J -(q_9 * q_10 * q_11 * q_12));
        //cout << K << endl;

        int q_14 = (Y + (Y/4) + J + 2);
        //cout << q_14 << endl;

        int L = (q_14 - C + (C/4));
        //cout << L << endl;

        int P = (L -((L/7)*7));
        //cout << P << endl;

        int Q = (K - P);
        //cout << Q << endl;

        int mon = (((Q+40)/44) + 3);
        //cout << mon << endl;

        int day = ((Q+28) - ((mon/4)*31));
        //cout << day << endl;

        cout << mon << " " << day << endl;
    }
    
    return -1;
}