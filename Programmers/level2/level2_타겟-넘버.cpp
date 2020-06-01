#include <string>
#include <vector>

//프로그래머스 level2_타겟-넘버

using namespace std;

int answer;

void dfs(vector<int> num, int target, int idx, int val){
    
    if(idx == num.size()){
        if(val == target) answer++;
        return;
    }
    dfs(num, target, idx+1, val + num[idx]);
    dfs(num, target, idx+1, val - num[idx]);
    return;    
}

int solution(vector<int> numbers, int target) {
    answer = 0;
    dfs(numbers,target,0,0);
    return answer;
}