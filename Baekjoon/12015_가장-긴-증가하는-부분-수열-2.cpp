// 백준 12015번 가장 긴 증가하는 부분 수열 2

// nlogn => 이분탐색

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<int> dp;
    int k;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (i == 0)
            dp.push_back(k);
        else if (dp.back() < k)
            dp.push_back(k);
        else {
            int idx = lower_bound(dp.begin(), dp.end(), k) - dp.begin();
            dp[idx] = k;
        }
    }
    cout << dp.size();

    return 0;
}