#include <string>
#include <iostream>

//프로그래머스 level1_문자열-내-p와-y의-개수

using namespace std;

bool solution(string s)
{
    int x = 0;
    for(char c: s){
        if(c == 'p' || c == 'P')
            x++;
        else if(c== 'y' || c =='Y')
            x--;
    }
    if(x !=0)
        return false;
    return true;
}