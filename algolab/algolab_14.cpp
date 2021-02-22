#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(){
    int numTestCases;
    cin >> numTestCases;

    for(int i= 0; i < numTestCases; i++){
        int firstx, secondx, firsty, secondy;
        int thirdx, thirdy;
        int ed, rd; // ed는 직선거리, rd는 직각거리
        int finalx, finaly;

        cin >> firstx >> firsty >> secondx >> secondy;

        cin >> thirdx >> thirdy;

        if(thirdx <= firstx){
            if(thirdy >= secondy){
                finalx = firstx;
                finaly = secondy;
                ed = ( pow(finalx - thirdx, 2) + pow(finaly - thirdy, 2) );
                rd = ( abs(finalx - thirdx) + abs(finaly - thirdy) );
                cout << ed << " " << rd << endl;
            }

            else if(firsty <= thirdy && thirdy <= secondy){
                finalx = firstx;
                finaly = thirdy;
                ed = ( pow(finalx - thirdx, 2) + pow(finaly - thirdy, 2) );
                rd = ( abs(finalx - thirdx) + abs(finaly - thirdy) );
                cout << ed << " " << rd << endl;
            }

            else if(thirdy <= firsty){
                finalx = firstx;
                finaly = firsty;
                ed = ( pow(finalx - thirdx, 2) + pow(finaly - thirdy, 2) );
                rd = ( abs(finalx - thirdx) + abs(finaly - thirdy) );
                cout << ed << " " << rd << endl;
            }
        }

        else if(firstx <= thirdx && thirdx <= secondx){
            if(thirdy >= secondy){
                finalx = thirdx;
                finaly = secondy;
                ed = ( pow(finalx - thirdx, 2) + pow(finaly - thirdy, 2) );
                rd = ( abs(finalx - thirdx) + abs(finaly - thirdy) );
                cout << ed << " " << rd << endl;
            }

            else if (firsty <= thirdy && thirdy <= secondy){
                cout << 0 << " " << 0 << endl;
            }

            else if (thirdy <= firsty){
                finalx = thirdx;
                finaly = firsty;
                ed = ( pow(finalx - thirdx, 2) + pow(finaly - thirdy, 2) );
                rd = ( abs(finalx - thirdx) + abs(finaly - thirdy) );
                cout << ed << " " << rd << endl;
            }
        }

        else if(secondx <= thirdx){
            if(secondy <= thirdy){
                finalx = secondx;
                finaly = secondy;
                ed = ( pow(finalx - thirdx, 2) + pow(finaly - thirdy, 2) );
                rd = ( abs(finalx - thirdx) + abs(finaly - thirdy) );
                cout << ed << " " << rd << endl;
            }

            else if(firsty <= thirdy && thirdy <= secondy){
                finalx = secondx;
                finaly = thirdy;
                ed = ( pow(finalx - thirdx, 2) + pow(finaly - thirdy, 2) );
                rd = ( abs(finalx - thirdx) + abs(finaly - thirdy) );
                cout << ed << " " << rd << endl;
            }

            else if(thirdy <= firsty){
                finalx = secondx;
                finaly = firsty;
                ed = ( pow(finalx - thirdx, 2) + pow(finaly - thirdy, 2) );
                rd = ( abs(finalx - thirdx) + abs(finaly - thirdy) );
                cout << ed << " " << rd << endl;
            }
        }
    }
    
    return -1;
}