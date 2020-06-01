#include <string>
#include <vector>

//프로그래머스 level2_행렬의-곱셈

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for(int i = 0;i<arr1.size();i++){
        vector<int> temp;
        for(int j = 0; j<arr2[0].size();j++){
            int val = 0;
            for(int k = 0;k<arr2.size();k++){
                val += arr1[i][k] * arr2[k][j]; 
            }
            temp.push_back(val);
        }
        answer.push_back(temp);
    }
    
    return answer;
}