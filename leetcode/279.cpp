class Solution {
public:
    int numSquares(int n)
    {
        int dp[10001];
        for (int i = 1; i <= n; i++) {
            dp[i] = 10001;
        }

        for (int i = 1; i * i <= n; i++) {
            dp[i * i] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= n - i; j++) {
                dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
            }
        }
        return dp[n];
    }
};