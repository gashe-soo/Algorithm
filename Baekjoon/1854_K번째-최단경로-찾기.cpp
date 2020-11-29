// 백준 1854번 K번째 최단경로 찾기

// heap 이용해서 k번째까지만 구하기

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> pi;

int n, m, k;
priority_queue<int> dist[1001];
vector<pi> adj[1001];

void dji()
{
    priority_queue<pi, vector<pi>, greater<pi>> pq;

    dist[1].push(0);
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        int c = pq.top().first;
        int from = pq.top().second;
        pq.pop();

        for (pi p : adj[from]) {
            int to = p.first, cost = p.second;
            if (dist[to].size() == k) {
                if (dist[to].top() > cost + c) {
                    dist[to].pop();
                    dist[to].push(cost + c);
                    pq.push({ cost + c, to });
                }
            } else {
                dist[to].push(cost + c);
                pq.push({ cost + c, to });
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
    }
    dji();

    for (int i = 1; i <= n; i++) {
        if (dist[i].size() < k) {
            cout << "-1\n";
        } else {
            cout << dist[i].top() << "\n";
        }
    }
    return 0;
}