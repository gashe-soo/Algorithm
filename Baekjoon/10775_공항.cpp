// 백준 10775번 공항

// union-find

#include <iostream>

using namespace std;

int n, m, ans, p[100001];
int plane[100001];

int find(int idx)
{
    if (p[idx] == idx)
        return idx;
    return p[idx] = find(p[idx]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        p[i] = i;

    for (int i = 0; i < m; i++) {
        cin >> plane[i];
    }

    for (int i = 0; i < m; i++) {
        int idx = find(plane[i]);
        if (idx == 0)
            break;
        p[idx] = idx - 1;
        ans++;
    }

    cout << ans;
    return 0;
}