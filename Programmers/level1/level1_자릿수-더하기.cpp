#include <iostream>

//프로그래머스 level1_자릿수-더하기

using namespace std;
int solution(int n)
{
    int answer = 0;
    int x = 10;
    
    while(n>=1){
        answer += n%x;
        n /= x;
    }
    

    return answer;
}