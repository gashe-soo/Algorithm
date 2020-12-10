// 백준 2096번 내려가기

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n, arr[100001][3], dp[3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    for (int i = 0; i < 3; i++) {
        dp[i] = arr[0][i];
    }

    for (int i = 1; i < n; i++) {
        int a = dp[0], b = dp[1], c = dp[2];

        dp[0] = max(a, b) + arr[i][0];
        dp[1] = max({ a, b, c }) + arr[i][1];
        dp[2] = max(b, c) + arr[i][2];
    }

    cout << max({ dp[0], dp[1], dp[2] }) << " ";

    for (int i = 0; i < 3; i++) {
        dp[i] = arr[0][i];
    }

    for (int i = 1; i < n; i++) {
        int a = dp[0], b = dp[1], c = dp[2];

        dp[0] = min(a, b) + arr[i][0];
        dp[1] = min({ a, b, c }) + arr[i][1];
        dp[2] = min(b, c) + arr[i][2];
    }

    cout << min({ dp[0], dp[1], dp[2] });
    return 0;
}