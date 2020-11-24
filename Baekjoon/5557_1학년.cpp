// 백준 5557번 1학년

// dp top down

#include <cstring>
#include <iostream>

using namespace std;
typedef long long ll;

int n, arr[101];
ll dp[101][21];

ll solve(int x, int y)
{
    if (y < 0 || y > 20)
        return 0;

    if (x == n - 2) {
        if (y == arr[n - 1])
            return 1;
        return 0;
    }

    ll& ret = dp[x][y];
    if (ret != -1)
        return ret;

    ret = 0;

    ret += solve(x + 1, y + arr[x + 1]);
    ret += solve(x + 1, y - arr[x + 1]);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(0, arr[0]);

    return 0;
}