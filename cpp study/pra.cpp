#include <iostream>

using namespace std;

int main(){
    double d;
    char *cp;
    int *ip;
    float *fp;
    double *dp;

    cp = (char*)&d;
    ip = (int*)&d;
    fp = (float*)&d;
    dp = (double*)&d;

    cout << &d << endl;

    d = 3.141592;

    cout << *cp << endl;
    cout << *ip << endl;
    cout << *fp << endl;
    cout << *dp << endl;

    return -1;
}