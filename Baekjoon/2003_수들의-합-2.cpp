// 백준 2003번 수들의-합-2

#include <iostream>

using namespace std;

int n, m, a[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int l = 0, r = 1;
    int sum = a[0];
    int ans = 0;
    while (r <= n) {

        if (sum == m) {
            ans++;
            sum -= a[l];
            l++;
        } else if (sum > m) {
            sum -= a[l];
            l++;
        } else {
            sum += a[r];
            r++;
        }
    }
    cout << ans;
    return 0;
}