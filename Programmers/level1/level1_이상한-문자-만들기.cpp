#include <string>
#include <vector>

// 프로그래머스 level1_이상한-문자-만들기

using namespace std;

string solution(string s) {
    int idx = 0;
    
    for(int i = 0;i<s.length();i++){
        if(s[i]==' ')
            idx = 0;
        else{
            if(idx % 2 ==0){
                s[i] =  toupper(s[i]);
            }else
                s[i] =  tolower(s[i]);
            idx++;
        }
    }
    
    return s;
}