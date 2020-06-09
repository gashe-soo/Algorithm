#include <string>
#include <vector>
#include <cmath>
#include <set>

//프로그래머스 level3_N으로-표현

using namespace std;

// 1. N번째 숫자는 1 U N-1 + 2 U N-2 .... N-1 U 1  (U는 합집합)

int make(int n, int cnt){
    int x =0;
    while(cnt--){
        x += pow(10,cnt);
    }
    return x*n;
}

int solution(int N, int number) {
    int answer = 0;
    vector<set<int>> dp(9);
    
    for(int i = 1;i<9;i++){
        dp[i].insert(make(N,i));         
    } 
    // 풀이 참고.
    for(int i =2;i<9;i++){
        for(int j = 1;j<i;j++){
            for(auto p : dp[j]){
                for(auto q : dp[i-j]){
                    dp[i].insert(p+q);
                    dp[i].insert(p-q);
                    dp[i].insert(p*q);
                    if(q!=0)
                        dp[i].insert(p/q);
                }
            }
        }
        if(dp[i].find(number)!=dp[i].end())
            return i;
    }
    
  
    
    return -1;
}