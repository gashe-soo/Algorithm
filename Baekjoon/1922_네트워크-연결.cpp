// 백준 1922번 네트워크-연결

// mst이므로 union - find 이용

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int n, m, a, b, c, p[1001], cnt;
vector<vector<int>> e;

int find(int idx)
{
    if (idx == p[idx])
        return idx;
    return p[idx] = find(p[idx]);
}

bool merge(int x, int y)
{
    a = find(x), b = find(y);
    if (a > b) {
        swap(a, b);
    }

    if (a == b)
        return false;
    p[b] = a;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        p[i] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        e.push_back({ c, a, b });
    }
    sort(e.begin(), e.end());
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (merge(e[i][1], e[i][2])) {
            cnt++;
            ans += e[i][0];
        }

        if (cnt == n - 1)
            break;
    }

    cout << ans;

    return 0;
}