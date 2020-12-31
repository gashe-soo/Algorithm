// 백준 2230번 수-고르기

#include <algorithm>
#include <iostream>
using namespace std;

int n, m, arr[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    int l = 0, r = 1;
    int ans = 2e9 + 1;
    while (r < n) {
        int v = arr[r] - arr[l];
        if (v >= m) {
            ans = min(ans, v);
            l++;
        } else {
            r++;
        }
    }
    cout << ans;
    return 0;
}