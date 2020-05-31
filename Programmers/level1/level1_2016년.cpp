#include <string>
#include <vector>

//프로그래머스 level1 2016년

using namespace std;

string solution(int a, int b) {
    int month[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    string date[7] ={"FRI","SAT","SUN","MON","TUE","WED","THU"};
    int day = -1;
    for(int i=0;i<a-1;i++){
        day +=month[i];
    }
    day +=b;
    
    return date[day%7];
    
}