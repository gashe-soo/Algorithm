// 백준 11437번 LCA

#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int n, m, a, b;
int depth[50001], p[50001][21], v[50001];
vector<int> adj[50001];

void makeTree(int parent, int now)
{

    depth[now] = depth[parent] + 1;
    v[now] = true;

    for (int to : adj[now]) {
        if (v[to])
            continue;
        p[to][0] = now;
        makeTree(now, to);
    }

    return;
}

int lca(int x, int y)
{
    if (depth[x] > depth[y]) {
        swap(x, y);
    }

    for (int i = 20; i >= 0; i--) {
        if ((1 << i) <= depth[y] - depth[x])
            y = p[y][i];
    }
    if (x == y)
        return x;

    for (int i = 20; i >= 0; i--) {
        if (p[x][i] != p[y][i]) {
            x = p[x][i];
            y = p[y][i];
        }
    }
    return p[x][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(p, -1, sizeof(p));

    depth[0] = -1;
    makeTree(0, 1);

    for (int j = 1; j <= 20; j++) {
        for (int i = 1; i <= n; i++) {
            p[i][j] = p[p[i][j - 1]][j - 1];
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }

    return 0;
}