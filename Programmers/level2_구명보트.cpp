#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <iostream>

//프로그래머스 level2 구명보트

using namespace std;

// 덱을 이용한 풀이 
int solution(vector<int> p, int limit) {
    int answer = 0;
    deque<int> dq;
    sort(p.begin(),p.end(),greater<int>());
    
    for(int w : p){
        dq.push_back(w);
    }
    
    while(!dq.empty()){
        if((dq.front()+dq.back())<=limit) //앞뒤가 같이 가능
            dq.pop_back();  // 뒤 제거
        if(!dq.empty())
            dq.pop_front(); // 앞은 매번 제거(2명까지만 탑승 가능함)
        answer++;        
    }
    
    
    
    return answer;
}