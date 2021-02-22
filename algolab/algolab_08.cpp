#include <iostream>

using namespace std;

int main(){
    int numTestCases;
    cin >> numTestCases;
    
    int size;
    char square[100][100];

    for(int k= 0; k < numTestCases; k++){
        cin >> size;
        int half = size/2;

        for (int i = half ; i >= 0; i--){

            for (int j = 0; j < size; j++){

                if (((half == j) || (j <= half + i)) && (j >= half - i)){

                    if (i% 2 == 0){

                        if (j % 2 == 0){
                            square[i][j] = '*';
                            }

                        else if (j % 2 == 1){
                            square[i][j] = '+';
                            }
                        }

				    else if (i % 2 == 1){
                        if (j % 2 == 1){
                            square[i][j] = '*';
                            }

					    else if (j % 2 == 0){
						    square[i][j] = '+';
                            }
                        }
                    }

			    else {
				    square[i][j] = '-';
			        }

		        }
	        }

        square[half][half] = '*';

	    for (int i = half; i >= 0; i--){

            for (int j = 0; j < size; j++){
                cout << square[i][j];
                }
                cout << ' ' << endl;
            }



	for (int i = 1; i <= half; i++){

		for (int j = 0; j < size; j++){

            if ((half == j) || (j <= half + i) && (j >= half - i)){

                if (i % 2 == 0){

                    if (j % 2 == 0){
						square[i][j] = '*';
					}

					else if (j % 2 == 1) {
						square[i][j] = '+';
					}
				}

				else if (i % 2 == 1) {

					if (j % 2 == 1) {
						square[i][j] = '*';
					}

					else if (j % 2 == 0) {
						square[i][j] = '+';
					}
				}
			}

			else {
				square[i][j] = '-';
			}

		}
    }

    square[half][half] = '*';
    
	for (int i = 1; i <= half; i++)//모래시계 하단 출력
	{
		for (int j = 0; j < size; j++){
            cout << square[i][j];
            }
        cout << ' ' << endl;
	}


}
    return -1;
}
    
    