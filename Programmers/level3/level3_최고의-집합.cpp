#include <string>
#include <vector>

//프로그래머스 level3 최고의 집합

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(n >s)
        return {-1};
    int val = s/n;
    int rem = s%n;
    answer.assign(n,val);
    int idx = n-1;
    for(int i = rem; i>0;i--){
        answer[idx]++;
        idx--;
    }
    
    
    return answer;
}