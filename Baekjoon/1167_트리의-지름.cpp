// 백준 1167번 트리의 지름

/*
nlogn 내에 해결해야 한다.

고려사항
1.루트부터 리프까지의 거리
bfs

2. 리프끼리의 거리.
루트부터 가장 먼 노드부터 다시 시작하여 가장 먼 노드를 찾기.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define SIZE 100001

using namespace std;

typedef pair<int, int> pi;

int v;
int dist[SIZE];
vector<pi> node[SIZE];

int answer;


void bfs(int start) {
	queue<int> q;
	memset(dist, -1, sizeof(dist));

	dist[start] = 0;
	q.push(start);
	
	while (!q.empty()) {
		int parent = q.front();
		q.pop();

		int base = dist[parent];
		
		for (int i = 0; i < node[parent].size(); i++) {
			int child = node[parent][i].first;
			int cost = node[parent][i].second;
			if (dist[child] != -1) continue;
			dist[child] = base + cost;
			q.push(child);
		}
	}
	return;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> v;
	int idx;
	for (int i = 0; i < v; i++) {
		cin >> idx;
		int a, b;
		cin >> a;
		while (a != -1) {
			cin >> b;
			node[idx].push_back({ a,b });
			cin >> a;
		}
	}
	int most = 1;
	bfs(most);
	most = max_element(dist, dist + v + 1) - dist;
	answer = max(answer, dist[most]);
	bfs(most);
	answer = max(answer, *max_element(dist, dist + v+1));
	cout << answer;

	return 0;
}

