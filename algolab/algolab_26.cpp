#include <iostream>
#include <fstream>

using namespace std;

void hw(std::ifstream&);
using namespace std;

int main(void) {

	std::ifstream fin;


	int num, i;

	fin.open("input.txt");// 파일 열기

	fin >> num;

	for (i = 0; i < num; i++)// 케이스 반복하기
	{
		hw(fin);
		//std::cout << ' ' << std::endl;
	}
	fin.close();

	return 0;
}


void hw(std::ifstream& fin) {// 파일 실체, 주소값 불러오기

	int num1, num2, cnt1 = 0, cnt2 = 0, cnt3 = 0;
	int tmp1 = 0, tmp2 = 0, tmp3;
	int A[100] = { 0, }, B[100] = { 0, };

	fin >> num1 >> num2;

	for (int i = 0; num1>0; i++)
	{
		A[i] = (num1 % 2);
		num1 = (num1 / 2);
		tmp1++;
	}
	for (int i = 0; num2>0; i++)
	{
		B[i] = (num2 % 2);
		num2 = (num2 / 2);
		tmp2++;
	}
	for (int k = tmp1 - 1; k >= 0; k--)
	{
		if (A[k] == 1) { cnt1++; }
	}
	for (int k = tmp2 - 1; k >= 0; k--)
	{
		if (B[k] == 1) { cnt2++; }
	}
	if (tmp1 > tmp2) { tmp3 = tmp1; }
	else if (tmp2 > tmp1) { tmp3 = tmp2; }
	else { tmp3 = tmp1; }
	for (int k = 0; k < tmp3; k++)
	{
		if (A[k] != B[k]) { cnt3++; }
	}

	cout << cnt1 << ' ' << cnt2 <<' '<< cnt3 << endl;
}