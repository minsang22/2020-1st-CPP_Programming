#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

typedef unsigned int uint;
int main() {



int numcases;
cin >> numcases;

while (numcases--)
{

int n;

const uint max = 0xffffffff;

vector<uint> array;

int count = 0;

int temp, temp1;



cin >> n;



for (int k = 1;; k *= 2)
{

for (int l = k;; l *= 3)
{

for (int m = l;; m *= 5)
{

array.push_back(m);

if (m>max / 5) break;

}

if (l>max / 3) break;

}

if (k>max / 2) break;

}

sort(array.begin(), array.end());



cout << array[n - 1] << endl;

}
return 0;

}