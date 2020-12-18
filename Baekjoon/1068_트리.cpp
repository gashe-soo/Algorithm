// 백준 1068번 트리

#include <iostream>
#include <vector>

using namespace std;

int n, d, r, ans, c;
vector<int> child[51];

void solve(int idx)
{
    if (idx == d)
        return;
    if (child[idx].size() == 0) {
        ans++;
        return;
    }

    if (child[idx][0] == d && child[idx].size() == 1) {
        ans++;
        return;
    }

    for (int i : child[idx]) {
        solve(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c == -1) {
            r = i;
            continue;
        }
        child[c].push_back(i);
    }
    cin >> d;

    solve(r);
    cout << ans;

    return 0;
}