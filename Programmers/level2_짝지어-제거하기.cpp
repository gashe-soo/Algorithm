#include <iostream>
#include <string>
#include <stack>
using namespace std;
// 프로그래머스 level2 짝지어 제거하기

int solution(string s)
{
    stack<char> st;
    
    for(char c : s){
        if(st.empty()) // 스택이 비었으면 푸시
            st.push(c);
        else{
            if(st.top()==c){ // 스택의 탑과 같다면 연속한 문자
                st.pop();   
            }else
                st.push(c); // 연속하지 않는 문자 push
        }
    }
    if(st.empty()) // 스택이 비었으면 문자 모두 제거
        return 1;
    return 0;

}