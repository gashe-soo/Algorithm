// 백준 1504번 특정한 최단 경로

// 다익스트라
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int n, e;
vector<pi> adj[801];
const int INF = 100000000;

int dji(int start, int end)
{
    vector<int> dist(n + 1, INF);
    priority_queue<pi, vector<pi>, greater<pi>> pq;

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int cost = pq.top().first, from = pq.top().second;
        pq.pop();

        if (dist[from] < cost)
            continue;
        for (pi p : adj[from]) {
            int newCost = p.first;
            int to = p.second;

            if (dist[to] > cost + newCost) {
                dist[to] = cost + newCost;
                pq.push({ dist[to], to });
            }
        }
    }
    return dist[end];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> e;
    int one, two;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ c, b });
        adj[b].push_back({ c, a });
    }

    cin >> one >> two;

    int ret = min(dji(1, one) + dji(one, two) + dji(two, n), dji(1, two) + dji(two, one) + dji(one, n));
    if (ret >= INF) {
        cout << -1;
    } else
        cout << ret;
    return 0;
}