// 프로그래머스 level2 이진 변환 반복하기

#include <string>
#include <vector>

using namespace std;

int zero, cnt;

// 0제거
string del(string s)
{
    string ret;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            ret += s[i];
        }
    }
    zero += s.size() - ret.size();
    return ret;
}

// 이진 변환
string tobinary(int c)
{
    cnt++;
    string ret;
    while (c) {
        ret = to_string(c % 2) + ret;
        c /= 2;
    }
    return ret;
}

vector<int> solution(string s)
{

    while (s != "1") {
        s = tobinary(del(s).size());
    }

    return { cnt, zero };
}