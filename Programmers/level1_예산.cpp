#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

// 프로그래머스 level1 예산
using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(),d.end());
    
    for(int val : d){
        if(budget>=val){
            budget -=val;
            answer++;   
        }else
            break;
    }
    
    return answer;
}