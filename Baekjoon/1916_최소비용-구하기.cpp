#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

// 백준 1916번 최소비용-구하기

using namespace std;

// 1. 도시간 최소비용 => 다익스트라.
// 2. 우선순위 큐 이용.

int map[1001][1001];
int dist[1001];
int INF = 987654321;
int n, m;

// 1.
int dji(int start, int end) {
	priority_queue<pair<int, int>> pq;

	pq.push({ 0,start });
	dist[start] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int from = pq.top().second;
		pq.pop();
		for (int i = 1; i <= n; i++) {
			if (map[from][i] !=INF) {
				if (dist[i] > dist[from] + map[from][i]) {
					dist[i] = dist[from] + map[from][i];
					pq.push({ dist[i],i });
				}
			}
		}
	}
	return dist[end];
}

int main() {
	cin >> n;
	cin >> m;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			map[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		map[start][end] = min(map[start][end], cost);
	}

	int start, end;
	cin >> start >> end;
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	
	cout << dji(start, end) << endl;

	return 0;
}