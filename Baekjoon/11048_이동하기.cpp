// 백준 11048번 이동하기

#include <algorithm>
#include <iostream>

using namespace std;

int n, m;
int arr[1001][1001];
int dp[1001][1001];

int dx[3] = { 1, 0, 1 };
int dy[3] = { 0, 1, 1 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    dp[0][0] = arr[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 3; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                dp[nx][ny] = max(dp[nx][ny], dp[i][j] + arr[nx][ny]);
            }
        }
    }
    cout << dp[n - 1][m - 1];
    return 0;
}