// 백준 11055번 가장 큰 증가 부분 수열

#include <algorithm>
#include <iostream>

using namespace std;

int a[1001];
int dp[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = a[i];
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], a[i] + dp[j]);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;

    return 0;
}