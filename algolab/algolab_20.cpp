#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
    
    ifstream infile;

    infile.open("input.txt");

    int numTestCases;

    infile >> numTestCases;

    for(int i= 0; i < numTestCases; i++){
        int a[132] = {0, };
        int b[132] = {0, };
        int gyo[132];
        int hap[132];
        int cha[132];
        int gcount = 0;
        int hcount = 0;
        int ccount = 0;
        int asize, bsize;
        int a_val, b_val;

        infile >> asize;

        for(int j = 0; j < asize; j++) {
            infile >> a_val;
            a[a_val] = 1;
        }

        infile >> bsize;

        for(int j = 0; j < bsize; j++) {
            infile >> b_val;
            b[b_val] = 1;
        }
        

        //여기부터 교집합 
        for(int j = 0; j < 132; j++) {
            if(a[j] == 1 && b[j] == 1){
                gyo[gcount] = j;
                gcount += 1;
            }
        }

        sort(gyo, gyo + gcount);

        cout << gcount << " ";

        for(int j = 0; j < gcount; j++) {
            cout << gyo[j] << " ";
        }
        cout << endl;


        //여기부터 합집합
        for(int j = 0; j < 132; j++){
            if(a[j] == 1 || b[j] == 1){
                hap[hcount] = j;
                hcount += 1;
            }
        }

        sort(hap, hap + hcount);

        cout << hcount << " ";

        for(int j = 0; j < hcount; j++) {
            cout << hap[j] << " ";
        }
        cout << endl;


        //여기부터 차집합
        for(int j = 0; j < 132; j++) {
            if(a[j] == 1 && b[j] == 0){
                cha[ccount] = j;
                ccount += 1;
            }
        }

        sort(cha, cha + ccount);

        cout << ccount << " ";

        for (int j = 0; j < ccount; j++) {
            cout << cha[j] << " ";
        }
        cout << endl;

    }
    
    return -1;
}