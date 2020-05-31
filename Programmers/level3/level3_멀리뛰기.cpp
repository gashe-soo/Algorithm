#include <string>
#include <vector>

using namespace std;

// 프로그래머스 level 3 멀리뛰기
long long jump[2001];

long long solution(int n) {
    long long answer = 0;
    int cnt = 1234567;
    
    jump[0] = 1;
    jump[1] = 1;
    //DP
    for(int i =2;i<=n;i++){ 
        jump[i] = (jump[i-1]+jump[i-2])%cnt;
    }
    
    return jump[n];
}