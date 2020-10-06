// 백준 2294번 동전

#include <algorithm>
#include <iostream>

using namespace std;

int n, k;
int coin[101];
int dp[100001];
const int INF = 987654321;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> coin[i];

    sort(coin, coin + n);

    for (int i = 1; i <= k; i++) {
        dp[i] = INF;
    }

    for (int i = 0; i < n; i++) {
        dp[coin[i]] = 1;
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (coin[j] <= i) {
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
            }
        }
    }
    if (dp[k] == INF)
        cout << -1;
    else
        cout << dp[k];
    return 0;
}