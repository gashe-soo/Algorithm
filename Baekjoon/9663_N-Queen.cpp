// 백준 9663번 N-Queen

#include <cmath>
#include <iostream>
using namespace std;

int n, ans;
int q[16];

bool check(int idx)
{
    for (int i = 0; i < idx; i++) {
        if (q[i] == q[idx])
            return false;
        if (abs(q[idx] - q[i]) == abs(idx - i))
            return false;
    }
    return true;
}

void solve(int idx)
{
    if (idx == n) {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
        q[idx] = i;
        if (check(idx)) {
            solve(idx + 1);
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    solve(0);

    cout << ans;
    return 0;
}