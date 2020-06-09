#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

// 백준 1939 중량제한.

using namespace std;

// 1. 길은 특정 중량 w보다 커야 한다.
// 1-1. bfs을 돌면서 만약 w보다 작으면 패스, 클 경우에만 확인
// 1-2. 도착지점에 도착했으면 w 가능 / 아니면 불가능
// 2. 이분탐색으로 가장 큰 w찾기.

vector<pair<int,int>> map[10001];
int n, m, depart, arrive;
bool v[10001];

// 1.
bool bfs(int w) {
	queue<int> q;
	memset(v, 0, sizeof(v));
	q.push(depart);
	v[depart] = true;

	while (!q.empty()) {
		int from = q.front();
		q.pop();
		for (int i = 0; i < map[from].size(); i++) {
			int to = map[from][i].first;
			int cost = map[from][i].second;
			// 1-1.
			if (cost >= w && !v[to]) {
				q.push(to);
				v[to] = true;
			}
		}
	}
	// 1-2.
	return v[arrive];
}

int main() {
	
	int answer = 0;
	cin >> n >> m;
	int w = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		w = max(w, c);
		map[a].push_back({ b,c });
		map[b].push_back({ a,c });
	}
	cin >> depart >> arrive;

	int low = 0, high = w;
	// 2.
	while (low <= high) {
		int mid = (low + high) / 2;
		if (bfs(mid)) {
			answer = max(answer,mid);
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	
	cout << answer;

	return 0;
}