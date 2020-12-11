// 백준 15681번 트리와 쿼리

#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int n, r, q, u, v;
int tree[100001];
vector<int> adj[100001];

int solve(int p, int c)
{
    int& ret = tree[c];
    if (ret != -1)
        return ret;

    ret = 1;
    for (int child : adj[c]) {
        if (p == child)
            continue;
        ret += solve(c, child);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(tree, -1, sizeof(tree));

    cin >> n >> r >> q;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    solve(0, r);

    for (int i = 0; i < q; i++) {
        cin >> u;
        cout << tree[u] << "\n";
    }

    return 0;
}