// 백준 1949번 우수-마을

#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int n, arr[10001], dp[10001][2];
vector<int> adj[10001];
bool v[10001];

int solve(int num, int f)
{
    int& ret = dp[num][f];
    if (ret != -1)
        return ret;

    ret = 0;
    v[num] = 1;
    for (int to : adj[num]) {
        if (v[to])
            continue;

        int a = solve(to, 0);
        if (f == 0)
            a = max(a, solve(to, 1));

        ret += a;
    }
    v[num] = 0;
    if (f)
        ret += arr[num];

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << max(solve(1, 0), solve(1, 1));
    return 0;
}