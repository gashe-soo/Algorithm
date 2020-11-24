// 백준 14284번 간선 이어가기

// 다익스트라

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int n, m, s, t;
vector<pi> adj[5001];
const int INF = 987654321;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
    }
    cin >> s >> t;

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<int> dist(n + 1, INF);
    pq.push({ 0, s });
    dist[s] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int from = pq.top().second;
        pq.pop();

        if (dist[from] < cost)
            continue;
        for (auto next : adj[from]) {
            int to = next.first;
            int c = next.second;
            if (dist[to] > cost + c) {
                dist[to] = c + cost;
                pq.push({ dist[to], to });
            }
        }
    }
    cout << dist[t];

    return 0;
}