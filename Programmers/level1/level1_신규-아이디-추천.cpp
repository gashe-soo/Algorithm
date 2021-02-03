// 프로그래머스 level1 카카오 2021 신규아이디 추천

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isAlpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return true;
    if (c >= 'A' && c <= 'Z')
        return true;
    return false;
}

bool isOk(char c)
{
    if (isAlpha(c))
        return true;
    if (c >= '0' && c <= '9')
        return true;
    if (c == '-' || c == '_' || c == '.')
        return true;
    return false;
}

string solution(string new_id)
{
    string answer = "";

    // 1.
    for (int i = 0; i < new_id.size(); i++) {
        if (isAlpha(new_id[i])) {
            new_id[i] = tolower(new_id[i]);
        }
    }

    // 2.
    for (int i = 0; i < new_id.size(); i++) {
        if (isOk(new_id[i])) {
            answer += new_id[i];
        }
    }

    // 3.
    string tmp;
    char now = answer[0];
    tmp += now;
    for (int i = 1; i < answer.size(); i++) {
        if (now != '.' || answer[i] != '.') {
            tmp += answer[i];
        }
        now = answer[i];
    }

    answer = tmp;
    tmp.clear();

    // 4.
    if (answer[0] == '.') {
        answer = answer.substr(1);
    }
    if (answer.back() == '.') {
        answer.pop_back();
    }
    // 5.
    if (answer.size() == 0) {
        answer = string(1, 'a');
    }
    // 6.
    if (answer.size() >= 16) {
        answer = answer.substr(0, 15);
    }
    if (answer.back() == '.') {
        answer.pop_back();
    }
    // 7.
    while (answer.size() <= 2) {
        answer += answer.back();
    }

    return answer;
}