// 백준 1786번 찾기

#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

string t, p;

vector<int> getpi()
{
    int size = p.size();
    vector<int> pi(size, 0);

    int begin = 1, matched = 0;

    while (begin + matched < size) {
        if (p[matched] == p[begin + matched]) {
            matched++;
            pi[begin + matched - 1] = matched;
        } else {
            if (matched == 0)
                begin++;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return pi;
}

vector<int> kmp()
{
    vector<int> pi = getpi();
    int size = p.size();
    vector<int> ret;
    int begin = 0, matched = 0;
    while (begin + size <= t.size()) {
        if (matched < size && p[matched] == t[begin + matched]) {
            matched++;

            if (matched == size)
                ret.push_back(begin);
        } else {
            if (matched == 0)
                begin++;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    getline(cin, t);
    getline(cin, p);

    vector<int> ret = kmp();

    cout << ret.size() << "\n";
    for (int i : ret) {
        cout << i + 1 << " ";
    }

    return 0;
}