#include <string>
#include <vector>
#include <algorithm>

// 프로그래머스 level1 문자열-내-마음대로-정렬하기
using namespace std;

int p;

bool cmp(string a , string b){
    if(a[p] == b[p])
        return a<b;
    return a[p]<b[p];
}

vector<string> solution(vector<string> strings, int n) {
    p = n;
    sort(strings.begin(),strings.end(),cmp);
    return strings;
}