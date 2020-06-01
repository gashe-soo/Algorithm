#include <string>
#include <vector>

//프로그래머스 level2_다음-큰-숫자

using namespace std;

// 1의 개수 같은지 확인
bool same(int a, int b){
    int sum = 0;
    while(a>=1){
        if(a%2 == 1)
            sum++;
        a /=2;
    }
    while(b>=1){
        if(b%2 ==1)
            sum--;
        b /=2;
    }
    if(sum == 0)
        return true;
    return false;
}

int solution(int n) {
    int answer = n+1;
    // 1의 개수가 같을 때까지 반복
    while(!same(n,answer++)){}
    return answer-1;
    
}