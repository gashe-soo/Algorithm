// 백준 1699번 제곱수의 합

// dp로 해결

#include <iostream>

using namespace std;
int dp[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    for (int i = 1; i * i <= n; i++) {
        dp[i * i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (dp[i] > dp[i - j * j] + 1 || dp[i] == 0)
                dp[i] = dp[i - j * j] + 1;
        }
    }

    cout << dp[n];

    return 0;
}