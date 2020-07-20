// 프로그래머스 level2_땅따먹기

// 0. 1행만은 본인이 기준.
// 1. 이전 행에서 자신의 칸을 제외하고 제일 큰 값을 취한다.
// 2. 이것이 누적되다보면 마지막 행에서 제일 큰 값이 최고점이 된다.

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int size = land.size();
    vector<vector<int>> ret(size,vector<int>(4,0));

    // 0. 1행은 자신이 기준.
    for(int i=0;i<4;i++){
        ret[0][i] = land[0][i];
    }
    
    // 2. 2행부터 마지막 행까지 1번 반복
    for(int i=1;i<size;i++){
        for(int j = 0;j<4;j++){
            // 1. n-1번 행 중 가장 큰 수
            vector<int> arr = ret[i-1];
            arr.erase(arr.begin()+j);
            int max = *max_element(arr.begin(),arr.end());
            ret[i][j] = land[i][j]+ max;
            
        }
    }    
    
    answer = *max_element(ret[size-1].begin(), ret[size-1].end());
    return answer;
}