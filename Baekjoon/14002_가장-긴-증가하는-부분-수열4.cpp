// 백준 14002번 가장-긴-증가하는-부분-수열 4

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int n, arr[1001], dp[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }

    int ans = 0;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if (ans < dp[i]) {
            ans = dp[i];
            idx = i;
        }
    }
    vector<int> ret;
    cout << ans << "\n";
    ret.push_back(arr[idx]);
    ans--;
    for (int i = idx - 1; i >= 0; i--) {
        if (dp[i] == ans && arr[i] < ret.back()) {
            ret.push_back(arr[i]);
            ans--;
        }
    }

    for (int i = ret.size() - 1; i >= 0; i--) {
        cout << ret[i] << " ";
    }

    return 0;
}