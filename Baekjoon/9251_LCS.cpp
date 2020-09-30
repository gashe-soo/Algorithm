// น้มุ 9251น๘ LCS

#include <iostream>
#include <string>

using namespace std;

int dp[1001][1001];
string s1, s2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m];
    return 0;
}