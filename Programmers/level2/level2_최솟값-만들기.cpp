#include <iostream>
#include<vector>
#include <algorithm>

//프로그래머스 level2_최솟값-만들기

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),greater<int>());
    
    for(int i = 0;i<A.size();i++){
        answer += A[i]*B[i];
    }
    

    return answer;
}