// 백준 1238번 파티

// 정방향, 역방향 다익스트라 2번으로 해결 가능하다!

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int n, m, x;
vector<pi> adj[1001], revadj[1001];
int d1[1001], d2[1001];

const int INF = 987654321;

void goX()
{
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({ 0, x });
    d1[x] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int from = pq.top().second;
        pq.pop();

        if (d1[from] < cost)
            continue;

        for (pi p : adj[from]) {
            int to = p.first;
            int newCost = p.second;

            if (d1[to] > newCost + cost) {
                d1[to] = newCost + cost;
                pq.push({ d1[to], to });
            }
        }
    }
}

void awayX()
{
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({ 0, x });
    d2[x] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int from = pq.top().second;
        pq.pop();

        if (d2[from] < cost)
            continue;

        for (pi p : revadj[from]) {
            int to = p.first;
            int newCost = p.second;

            if (d2[to] > newCost + cost) {
                d2[to] = newCost + cost;
                pq.push({ d2[to], to });
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> x;

    int a, b, c;
    for (int i = 0; i < m; i++) {

        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
        revadj[b].push_back({ a, c });
    }
    for (int i = 1; i <= n; i++) {
        d1[i] = INF;
        d2[i] = INF;
    }
    goX();
    awayX();

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, d1[i] + d2[i]);
    }

    cout << ans;

    return 0;
}