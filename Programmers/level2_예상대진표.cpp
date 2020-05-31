#include <iostream>

using namespace std;

//프로그래머스 level2 예상 대진표

// n 제곱일 때 n 구하기
int pow(int n){
    int ans = 0;
    while(n>1){
        n /=2;
        ans++;
    }
    return ans;
}

// n(=2^k)을 절반으로 나누었을 때 서로 다른 그룹에 있으면 k번째에 만난다(트리 특성)
int count(int n, int a, int b){
    int line = n/2;
    if(line >=a && line <b) // a,b가 서로 다른 그룹
        return pow(n);
    else if (a>line && b>line) // a,b가 모두 기준보다 클 때
        return count(line,a-line,b-line);
    else // a,b가 모두 기준보다 작을 때
        return count(line,a,b);
}

int solution(int n, int a, int b)
{
    // n, 작은 수, 큰 수로 count 하기
    if (a>b)
        return count(n,b,a);
    else
        return count(n,a,b);

}