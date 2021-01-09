// 백준 2159번 케익-배달

/*
dp 유형 문제
격자 10만*10만이고 순서대로 진행해야 하므로 이전 위치만 고려하면 된다.


*/

#include <cmath>
#include <iostream>
#define MAX 100001

using namespace std;
typedef long long ll;

int n, beforeX, beforeY;
int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, -1, 1 };
ll dp[MAX][5];
const ll INF = 1e16;

bool check(int x, int y)
{
    if (x < 0 || x >= MAX - 1 || y < 0 || y >= MAX - 1)
        return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> beforeX >> beforeY;

    int x, y;
    for (int i = 1; i < MAX; i++) {
        for (int j = 0; j < 5; j++) {
            dp[i][j] = INF;
        }
    }

    cin >> x >> y;

    // 처음은 무조건 시작점에서 시작해야 하므로 따로 계산
    for (int i = 0; i < 5; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        int d = abs(beforeX - nx) + abs(beforeY - ny);
        dp[0][i] = d;
    }

    beforeX = x, beforeY = y;

    for (int i = 1; i < n; i++) {
        cin >> x >> y;

        for (int j = 0; j < 5; j++) {
            int fromX = beforeX + dx[j], fromY = beforeY + dy[j]; // 이전 5개의 위치에서 새로운 5개의 위치까지의 거리 계산
            if (!check(fromX, fromY))
                continue;
            for (int k = 0; k < 5; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (!check(nx, ny))
                    continue;
                int d = abs(fromX - nx) + abs(fromY - ny);
                dp[i][k] = min(dp[i][k], dp[i - 1][j] + d);
            }
        }
        beforeX = x, beforeY = y;
    }
    ll ans = INF;
    for (int i = 0; i < 5; i++) {
        ans = min(ans, dp[n - 1][i]);
    }
    cout << ans;

    return 0;
}