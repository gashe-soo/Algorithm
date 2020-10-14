// 백준 11057번 오르막 수

// dp bottom - up

#include <iostream>

using namespace std;

int dp[1001][10];
const int NUM = 10007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                if (k > j)
                    break;
                dp[i][j] += dp[i - 1][k];
            }
            dp[i][j] %= NUM;
        }
    }

    int ans = 0;
    for (int i = 0; i < 10; i++)
        ans += dp[n][i];
    cout << ans % NUM;

    return 0;
}