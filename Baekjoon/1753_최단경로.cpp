// 백준 1753번 최단경로

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> pi;

int v, e, s;
vector<pi> adj[20001];
const int INF = 987654321;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> v >> e;
    cin >> s;

    int a, b, c;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
    }

    vector<int> dist(v + 1, INF);

    priority_queue<pi, vector<pi>, greater<pi>> pq;

    dist[s] = 0;
    pq.push({ 0, s });

    while (!pq.empty()) {
        int cost = pq.top().first;
        int from = pq.top().second;
        pq.pop();

        if (dist[from] < cost)
            continue;
        for (pi p : adj[from]) {
            int to = p.first;
            int newCost = p.second;
            if (dist[to] > cost + newCost) {
                dist[to] = cost + newCost;
                pq.push({ dist[to], to });
            }
        }
    }

    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF) {
            cout << "INF\n";
        } else {
            cout << dist[i] << "\n";
        }
    }

    return 0;
}