#include <iostream>

using namespace std;

int main(){
    int numTestCases;
    cin >> numTestCases;

    for(int i= 0; i < numTestCases; i++){
        int people; //직원 숫자
        int h1, h2, m1, m2, s1, s2; //각각 시작시간, 끝시간, 시작분, 끝분, 시작초, 끝초
        int sumd = 0;
        int sumh = 0;
        int summ = 0;
        int sums = 0;  //합의 날짜, 시간, 분, 초 (합이 몇일지 모르니까 0으로 초기화해줌)

        cin >> people;
        for (int k = 0; k < people; k++){
            cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
            
            if (s2 - s1 < 0){
                s2 += 60;
                m2 -= 1;
            }

            if (m2 - m1 < 0){
                m2 += 60;
                h2 -= 1;
            }

            sumh += h2 - h1;
            summ += m2 - m1;
            sums += s2 - s1;
        }
        
        if (sums > 60){
            summ += sums/60;
            sums = sums%60;
        }
        
        if (summ > 60){
            sumh += summ/60;
            summ = summ%60;
        }

        if (sumh > 24){
            sumd += sumh/24;
            sumh = sumh%24;
        }
        
        cout << sumd << " " << sumh << " " << summ << " " << sums << endl;
    }
    
    return -1;
}