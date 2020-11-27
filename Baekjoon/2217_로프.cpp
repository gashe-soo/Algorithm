// 백준 2217번 로프

#include <algorithm>
#include <iostream>
using namespace std;

int n, r[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    sort(r, r + n);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans = max(ans, (r[i] * (n - i)));
    }
    cout << ans;

    return 0;
}