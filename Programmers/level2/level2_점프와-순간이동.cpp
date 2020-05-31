#include <iostream>
using namespace std;

//프로그래머스 level2 점프와 순간이동

int solution(int n)
{
    int ans = 1;
    while(n>1){
        if(n%2==1)
            ans++;
        n /=2;
    }
   
    return ans;
}