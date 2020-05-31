#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

// 프로그래머스 level3 입국심사

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long left =1;
    long long right = *max_element(times.begin(),times.end())*(long long)n;
    
    // 이분 탐색
    while(left<right){
        long long mid = (left+right)/2;
        long long sum =0;
        for(int i=0;i<times.size();i++){
            sum += mid/times[i];
        }
        if(sum>=n)
            right = mid;
        else if(sum<n)
            left = mid+1;
        
    }
    answer = right;
    return answer;
}