#include <string>
#include <vector>

//프로그래머스 level1_콜라츠-추측

using namespace std;

int solution(int num) {
    int time = 0;
    long long n= num;
    while(n !=1 && time<500){
        if(n %2 ==0)
            n /=2;
        else
            n = 3*n +1;
        time++;
    }
    if(time == 500)
        return -1;
    
    return time;
}