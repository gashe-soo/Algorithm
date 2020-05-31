#include <string>
#include <vector>
#include <algorithm>

//프로그래머스 level1_문자열-내림차순으로-배치하기

using namespace std;

string solution(string s) {
    sort(s.begin(),s.end(),greater<char>());
    
    return s;
}