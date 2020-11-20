// 백준 2225번 합분해

#include <cstring>
#include <iostream>

using namespace std;

int n, k;
const int MOD = 1e9;
int dp[201];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;

    for (int i = 0; i <= n; i++)
        dp[i] = 1;

    for (int i = 2; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            dp[j] += dp[j - 1] % MOD;
            dp[j] %= MOD;
        }
    }

    cout << dp[n];
    return 0;
}