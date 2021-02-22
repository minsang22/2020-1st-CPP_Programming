
/*************************************************************************
*                                                                        *
* Problem :                                                              *
*                         모래시계 출력하기                              *
*                                                                        *
*************************************************************************/
/*************************************************************************
*                                                                        *
* 국민대학교 전자정보통신대학 컴퓨터공학부 1 학년                        *
* 20153183 박호준                                                        *
*                                                                        *
*************************************************************************/

#include <iostream>
#include <fstream>


void hw(std::ifstream&);


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

	int a;
	int i, j;
	char arr[100][100];

	fin >> a;


	for (i = (a / 2) ; i >= 0; i--)// 상단 조건
	{
		for (j = 0; j < a; j++)
		{
			if (((a / 2 == j) || (j <= (a / 2) + i)) && (j >= (a / 2) - i)) {
			
				if (i% 2 == 0) { // i 가 짝수일 때
					if (j % 2 == 0) { // j의 짝수열마다 *
						arr[i][j] = '*';
					}
					else if (j % 2 == 1) { // 아니면 +
						arr[i][j] = '+';
					}
				}

				else if (i % 2 == 1) { // i가 홀수일 때
					if (j % 2 == 1) { // j의 홀수열마다 *
						arr[i][j] = '*';
					}
					else if (j % 2 == 0) { //아니면 -
						arr[i][j] = '+';
					}
				}
			}
			else {
				arr[i][j] = '-';
			}

		}
	}

	for (i = (a / 2); i >= 0; i--)// 모래시계 상단 출력
	{
		for (j = 0; j < a; j++)
		{
			std::cout << arr[i][j];
		}
		std::cout << ' ' << std::endl;
	}



	for (i = 1; i <= (a / 2); i++)// 하단 조건
	{

		for (j = 0; j < a; j++)
		{
			if ((a / 2 == j) || (j <= (a / 2) + i) && (j >= (a / 2) - i)) {
				if (i % 2 == 0) {
					if (j % 2 == 0) {
						arr[i][j] = '*';
					}
					else if (j % 2 == 1) {
						arr[i][j] = '+';
					}
				}
				else if (i % 2 == 1) {
					if (j % 2 == 1) {
						arr[i][j] = '*';
					}
					else if (j % 2 == 0) {
						arr[i][j] = '+';
					}
				}
			}
			else {
				arr[i][j] = '-';
			}

		}
	}

	for (i = 1; i <= (a / 2); i++)//모래시계 하단 출력
	{
		for (j = 0; j < a; j++)
		{
			std::cout << arr[i][j];
		}
		std::cout << ' ' << std::endl;
	}


}