#include <string>
#include <vector>

// 프로그래머스 level3_하노이의-탑

using namespace std;
vector<vector<int>> answer;

void hanoi(int a, int b, int c, int n){
    if(n==1){
        answer.push_back({a,c});
        return;
    }
    hanoi(a,c,b,n-1);
    hanoi(a,b,c,1);
    hanoi(b,a,c,n-1);
    return;
}

vector<vector<int>> solution(int n) {
    hanoi(1,2,3,n);
    return answer;
}