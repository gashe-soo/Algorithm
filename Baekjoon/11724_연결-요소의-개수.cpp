// 백준 11724번 연결 요소의 개수

// 1. bfs
// 2. union-find

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> adj[1001];
int cnt, n, m;
/*

bool v[1001];

void bfs(int s)
{
    if (v[s])
        return;
    cnt++;
    queue<int> q;

    v[s] = true;
    q.push(s);

    while (!q.empty()) {
        int from = q.front();
        q.pop();

        for (auto to : adj[from]) {
            if (v[to])
                continue;
            q.push(to);
            v[to] = true;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        bfs(i);
    }
    cout << cnt;

    return 0;
}
*/

int p[1001];

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
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    cnt = n;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        int x = find(a);
        int y = find(b);
        if (x != y)
            cnt--;
        p[y] = x;
    }

    cout << cnt;
    return 0;
}