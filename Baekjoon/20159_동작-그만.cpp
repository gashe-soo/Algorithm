// 백준 20159번 동작 그만. 밑장 빼기냐?

// 누적합
#include <algorithm>
#include <iostream>

using namespace std;
int n;
int f[50002], s[50002];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    for (int i = 1; i <= n / 2; i++) {
        cin >> f[i] >> s[i];
        f[i] += f[i - 1];
        s[i] += s[i - 1];
    }

    int ans = f[n / 2];
    for (int i = 0; i <= n / 2; i++) {
        ans = max(ans, f[i] + s[n / 2 - 1] - s[i - 1]);
        ans = max(ans, f[i] + s[n / 2] - s[i]);
    }

    cout << ans;

    return 0;
}