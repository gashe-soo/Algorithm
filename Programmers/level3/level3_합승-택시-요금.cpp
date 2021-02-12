// 프로그래머스 level3 합승 택시 요금

// 다익스트라 3번으로 해결

#include <climits>
#include <queue>
#include <string>
#include <vector>

using namespace std;
typedef pair<int, int> pi;

const int INF = 2e9 + 1;

int dist[3][201];
vector<pi> adj[201];

void dji(int start, int idx)
{
    priority_queue<pi, vector<pi>, greater<pi>> pq;

    pq.push({ 0, start });
    dist[idx][start] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int from = pq.top().second;
        pq.pop();

        if (dist[idx][from] < cost)
            continue;

        for (pi p : adj[from]) {
            int to = p.first;
            int ncost = p.second;

            if (dist[idx][to] > cost + ncost) {
                dist[idx][to] = cost + ncost;
                pq.push({ dist[idx][to], to });
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    int answer = INT_MAX;

    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
    }

    for (int i = 0; i < fares.size(); i++) {
        int x = fares[i][0], y = fares[i][1], c = fares[i][2];

        adj[x].push_back({ y, c });
        adj[y].push_back({ x, c });
    }

    dji(s, 0);
    dji(a, 1);
    dji(b, 2);

    for (int i = 1; i <= n; i++) {
        answer = min(answer, dist[0][i] + dist[1][i] + dist[2][i]);
    }

    return answer;
}