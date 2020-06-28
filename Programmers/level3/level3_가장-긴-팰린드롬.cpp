#include <string>

// 프로그래머스 level3_가장-긴-팰린드롬

using namespace std;


int solution(string s)
{
    int answer=0;
    int size = s.length();
    for(int i=size;i>=1;i--){
        if(i<answer)
            continue;
        for(int j=0;j<=size-i;j++){
            bool flag = true;
            for(int k=0;k<=i/2;k++){
                if(s[j+k] != s[j+i-1-k]){
                    flag = false;
                    break;
                }
            }
            if(flag)
                answer = answer>i?answer:i;
        }
    }
    
    return answer;
}