// 백준 1967번 트리의 지름

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> pi;

int n;
vector<pi> adj[10001];
int far = 0;

int bfs(int s)
{
    queue<pi> q;
    vector<int> dist(n + 1, 0);

    q.push({ 0, s });
    dist[s] = 0;

    while (!q.empty()) {
        int cost = q.front().first;
        int from = q.front().second;
        q.pop();
        for (pi p : adj[from]) {
            if (dist[p.first])
                continue;
            dist[p.first] = cost + p.second;
            q.push({ dist[p.first], p.first });
        }
    }

    far = max_element(dist.begin(), dist.end()) - dist.begin();
    return dist[far];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int a, b, c;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
    }

    int r1 = bfs(1);
    int r2 = bfs(far);

    cout << max(r1, r2);

    return 0;
}