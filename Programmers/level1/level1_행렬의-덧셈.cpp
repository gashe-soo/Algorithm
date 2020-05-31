#include <string>
#include <vector>

//프로그래머스 level1_행렬의-덧셈

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int col = arr1.size();
    int row = arr1[0].size();
    for(int i = 0;i<col;i++){
        vector<int> t;
        for(int j = 0; j<row;j++){
            t.push_back(arr1[i][j]+arr2[i][j]);
        }
        answer.push_back(t);
    }
    
    return answer;
}