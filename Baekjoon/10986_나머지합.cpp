// 백준 10986번 나머지합

#include <iostream>

using namespace std;
typedef long long ll;

ll cnt[1001];
ll sum[1000001];
int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    int val;
    for (int i = 1; i <= n; i++) {
        cin >> val;

        sum[i] = sum[i - 1] + val;
        sum[i] %= m;

        cnt[sum[i]]++;
    }

    ll ans = cnt[0];
    for (int i = 0; i < m; i++) {
        ans += cnt[i] * (cnt[i] - 1) / 2;
    }

    cout << ans;

    return 0;
}