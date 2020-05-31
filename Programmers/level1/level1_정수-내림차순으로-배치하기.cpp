#include <string>
#include <vector>
#include <algorithm>

//프로그래머스 level1_정수-내림차순으로-배치하기

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string s =  to_string(n);
    sort(s.begin(),s.end(),greater<char>());
    answer = stoll(s);
    return answer;
}