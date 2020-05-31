#include <string>
#include <vector>

//프로그래머스 level1_문자열-다루기-기본

using namespace std;

bool solution(string s) {
    if(s.length()!=4 && s.length()!=6)
        return false;
    for(char c:s)
        if(c>'9' || c<'0')
            return false;
    return true;
}