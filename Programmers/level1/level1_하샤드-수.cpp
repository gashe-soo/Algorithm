#include <string>
#include <vector>

//프로그래머스 level1_하샤드-수

using namespace std;

bool solution(int x) {
    int sum = 0;
    int n = x;
    
    while(n>=1){
        sum += n % 10;
        n /= 10;
    }
    if(x%sum==0)
        return true;
    return false;
}