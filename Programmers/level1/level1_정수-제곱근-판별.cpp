#include <string>
#include <vector>
#include <cmath>

//프로그래머스 level1_정수-제곱근-판별

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long s = sqrt(n);
    
    if(s*s == n)
        return (s+1)*(s+1);
    return -1;
}