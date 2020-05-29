#include <string>
#include <vector>
#include <algorithm>

//프로그래머스 level2 탑
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    
    int n = heights.size();
    for(int i=n-1;i>=0;i--){
        for(int j = i-1;j>=0;j--){
            if(heights[i]<heights[j]){
                answer.push_back(j+1);
                break;
            }
            if(j==0)
                answer.push_back(0);
        }
    }
    answer.push_back(0);
    
    reverse(answer.begin(),answer.end());
    
    return answer;
}