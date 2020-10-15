//프로그래머스 level1_3진수 뒤집기

#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;

    string s;
    while (n >= 3) {
        s += to_string(n % 3);
        n /= 3;
    }
    s += to_string(n);
    int k = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        answer += k * (s[i] - '0');
        k *= 3;
    }

    return answer;
}