#include <string>
#include <vector>

//프로그래머스 level1 시저암호

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i=0;i<s.length();i++){
        if(s[i]==' ')
            answer+=s[i];
        else if(s[i]>='a'&& s[i]<='z')
            answer += 'a'+ (s[i]-'a'+n)%26;
        else
            answer += 'A'+ (s[i]-'A'+n)%26;
    }
    
    return answer;
}