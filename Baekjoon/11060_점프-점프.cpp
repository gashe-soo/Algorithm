// 백준 11060번 점프-점프

#include <iostream>

using namespace std;

int n, arr[1000], dp[1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = 10001;
    }
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= arr[i]; j++) {
            if (i + j >= n)
                break;
            dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
    }

    if (dp[n - 1] != 10001) {
        cout << dp[n - 1];
    } else {
        cout << -1;
    }

    return 0;
}