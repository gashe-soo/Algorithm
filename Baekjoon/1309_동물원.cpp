// ?? 1309? ???

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> dp(N + 1, 1);

    dp[1] = 3;
    for (int i = 2; i <= N; i++) {
        dp[i] = (2 * dp[i - 1] + dp[i - 2]) % 9901;
    }
    cout << dp[N];
    return 0;
}