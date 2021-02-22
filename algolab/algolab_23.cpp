#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char arr[100][100];
int check[100][100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int x, int y, int cnt){
    check[x][y] = 1;
    for (int z = 1; z < 5; z++){
        int nx = x + dx[z - 1];
        int ny = y + dy[z - 1];
        if (arr[nx][ny] == '.' && check[nx][ny] == 0){
            cnt = dfs(nx, ny, cnt + 1);
        }
    }

    return cnt;
}

bool compare(int a, int b){
    return a > b;
}

int main(){
    int numTestCases;
    cin >> numTestCases;

    for(int i= 0; i < numTestCases; i++){ 
        int row, col;
        cin >> col >> row;

        for(int j = 0; j < row; j++){
            for(int k = 0; k < col; k++){
                cin >> arr[j][k];
            }
        }

        for(int j = 0; j < row; j++){
            for(int k = 0; k < col; k++){
                check[j][k] = 0;
            }
        }

        vector<int> ans;
        for(int j = 0; j < row; j++){
            for(int k = 0; k < col; k++){
                if(arr[j][k] == '.' && check[j][k] == 0){
                    ans.push_back(dfs(j, k, 1));
                }
            }
        }

        sort(ans.begin(), ans.end(), compare);
        cout << ans.size() << endl;
        for(int j = 0; j < ans.size(); j++){
            cout << ans[j] << " ";
        }
        cout << endl;

    }
    
    return -1;
}