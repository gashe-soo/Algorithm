// 백준 1065번 한수

#include <iostream>

using namespace std;

bool check(int k)
{
    if (k == 1000)
        return false;
    int h = k / 100;
    int t = (k % 100) / 10;
    int o = k % 10;

    if ((h - t) == (t - o))
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int ans = 0;
    if (n < 100) {
        ans = n;
    } else {
        ans = 99;
        for (int i = 100; i <= n; i++) {
            if (check(i))
                ans++;
        }
    }

    cout << ans;

    return 0;
}