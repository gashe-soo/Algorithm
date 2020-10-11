// 백준 11052번 카드 구매하기

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int n;
int card[1001];
int dp[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> card[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], dp[i - j] + card[j]);
        }
    }
    cout << dp[n];
    return 0;
}