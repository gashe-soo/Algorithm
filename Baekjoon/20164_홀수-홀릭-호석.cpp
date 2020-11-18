// 백준 20164번 홀수 홀릭 호석

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int n;
int in = 100;
int ax;

int cal(int val)
{
    string s = to_string(val);
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        int c = s[i] - '0';
        if (c % 2)
            ans++;
    }
    return ans;
}

void solve(int now, int val)
{
    now += cal(val);
    if (val < 10) {
        in = min(in, now);
        ax = max(ax, now);
        return;
    } else if (val < 100) {
        solve(now, (val / 10 + val % 10));
    } else {
        string s = to_string(val);
        int size = s.size();
        for (int i = 1; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                int nv = stoi(s.substr(0, i)) + stoi(s.substr(i, j - i)) + stoi(s.substr(j));
                solve(now, nv);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    solve(0, n);
    cout << in << " " << ax;
    return 0;
}