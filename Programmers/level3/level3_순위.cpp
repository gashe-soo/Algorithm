#include <string>
#include <vector>
#include <cstring>

// 프로그래머스 level3_순위

// 플로이드 와샬 알고리즘 사용

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    bool arr[101][101];
    memset(arr, 0, sizeof(arr));
    for(int i = 0; i < results.size(); i++){
        int a = results[i][0];
        int b = results[i][1];
        arr[a][b] = true;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(arr[i][k] && arr[k][j]) arr[i][j] = true;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= n; j++)
            cnt += (arr[i][j] + arr[j][i]);
        if(cnt == n-1) answer++;
    }
    return answer;
}