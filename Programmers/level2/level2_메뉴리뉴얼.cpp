// 프로그래머스 level2 메뉴 리뉴얼

// 모든 가능한 조합 확인하여 개수 파악

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, int> cnt;
unordered_map<int, vector<string>> arr;

void go(string total, vector<bool>& v, int idx, string now, int len, vector<string>& arr)
{
    if (now.size() == len) {
        arr.push_back(now);
        return;
    }
    for (int i = idx + 1; i < total.size(); i++) {
        if (!v[i]) {
            v[i] = true;
            go(total, v, i, now + total[i], len, arr);
            v[i] = false;
        }
    }
}

vector<string> substr(string a, int len)
{
    vector<bool> v(a.size(), 0);
    vector<string> ret;
    go(a, v, -1, "", len, ret);
    return ret;
}

void subString(string a)
{
    for (int i = 2; i <= a.size(); i++) {
        vector<string> ret = substr(a, i);

        for (string s : ret) {

            if (!cnt[s]) {
                arr[i].push_back(s);
            }
            cnt[s]++;
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;

    for (int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
        subString(orders[i]);
    }

    for (int i = 0; i < course.size(); i++) {
        int len = course[i];

        vector<string> tmp;
        int maxVal = 0;

        for (string s : arr[len]) {
            if (cnt[s] < 2)
                continue;
            if (maxVal < cnt[s]) {
                maxVal = cnt[s];
                tmp.clear();
                tmp.push_back(s);
            } else if (maxVal == cnt[s]) {
                tmp.push_back(s);
            }
        }
        for (string s : tmp) {
            answer.push_back(s);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}