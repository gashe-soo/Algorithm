#include<string>

//프로그래머스 level2_올바른-괄호

using namespace std;

bool solution(string s)
{
    int sum = 0;
    for(char c : s){
        if(sum<0)
            return false;
        if(c == '(')
            sum++;
        else
            sum--;
    }
   return sum==0;
}