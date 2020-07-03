#include <string>
#include <vector>

//프로그래머스 level2_숫자의-표현

// 1. 규칙성이 있다. 
// 1-1. 연속된 숫자가 1개일때는 1씩 증가. 2개일때는 2씩 증가
// 1-2. 연속된 숫자가 2개일때는 3부터 2씩 증가, 
// 2. n이 일단 최대 몇 개의 연속된 자연수로 가능한지 확인
// 3. 식을 세워서 확인.

using namespace std;

int find(int n){
    for(int i=1;i<=n/2;i++){
        if(i*(i+1)>=2*n){
            return i;
        }
    }
}

int solution(int n) {
    int answer = 0;
    
    int k = find(n);
    int mok = 1, rem = 0;
    
    for(int i=1;i<=k;i++){
        mok = i;
        rem +=i-1;
        if( (n-rem)%mok == 0)
            answer++;
    }
    
    return answer;
}