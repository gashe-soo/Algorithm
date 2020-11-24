// 백준 1890번 점프

#include <cstring>
#include <iostream>

using namespace std;
typedef long long ll;

int n, map[101][101];
ll dp[101][101];

ll solve(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= n)
        return 0;

    if (x == n - 1 && y == n - 1)
        return 1;

    ll& ret = dp[x][y];
    if (ret != -1)
        return ret;

    ret = 0;

    ret += solve(x + map[x][y], y);
    ret += solve(x, y + map[x][y]);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    cout << solve(0, 0);
    return 0;
}