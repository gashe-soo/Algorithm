// 백준 16432번 떡장수와-호랑이

#include <iostream>

using namespace std;

int n, m, t;
int arr[1001][10];
bool v[1001][10];
int ans[1001];

bool solve(int now, int prev)
{
    if (now == n) {
        return true;
    }

    for (int i = 1; i < 10; i++) {
        if (i == prev)
            continue;
        if (arr[now][i] && !v[now + 1][i]) {
            v[now + 1][i] = 1;
            ans[now] = i;
            if (solve(now + 1, i))
                return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> t;
            arr[i][t] = 1;
        }
    }

    if (solve(0, 0)) {
        for (int i = 0; i < n; i++) {
            cout << ans[i] << "\n";
        }
    } else {
        cout << -1;
    }

    return 0;
}