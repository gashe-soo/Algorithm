#include <string>
#include <vector>

//프로그래머스 level2_JadenCase-문자열-만들기

using namespace std;

string solution(string s) {
    int c=0;

    for(int i=0; i<s.length();i++)
    {
        if(s[i]==' '){
            c=0; continue;
        }
        else if(c==0){
            s[i]=toupper(s[i]);
        }
        else
            s[i]=tolower(s[i]);
        c++;
    }
    return s;
}