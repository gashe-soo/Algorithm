// 백준 13905번 세부

/*
중량제한과 동일한 문제

이분탐색으로 최소를 찾는다.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;
int n, m, s, e;
vector<pi> h[100001];
bool v[100001];

bool bfs(int val) {
	queue<int> q;
	memset(v, 0, sizeof(v));

	q.push(s);
	v[s] = true;

	while (!q.empty()) {
		int from = q.front();
		q.pop();

		for (int i = 0; i < h[from].size(); i++) {
			int to = h[from][i].first;
			int cost = h[from][i].second;
			if (cost < val || v[to]) continue;
			q.push(to);
			v[to] = true;
		}
	}
	return v[e];
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> s >> e;
	int right = 0;
	for (int i = 0; i < m; i++) {
		int h1, h2, k;
		cin >> h1 >> h2 >> k;
		right = max(right, k);
		h[h1].push_back({ h2,k });
		h[h2].push_back({ h1,k });
	}

	int left = 0;
	int answer = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (bfs(mid)) {
			answer = max(answer, mid);
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << answer;

	return 0;
}