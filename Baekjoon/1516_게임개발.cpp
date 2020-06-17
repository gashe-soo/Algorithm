#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

// 백준 1516번 게임 개발

using namespace std;

// 위상 정렬
// 연결된 차수가 0인 노드부터 하나씩 삭제.
// 삭제하면서 연결 노드의 총 시간을 기존 시간과 수정된 시간 중 가장 큰 것으로 할당.
// 다시 연결된 차수가 0인 것을 큐에 push

typedef pair<int, int> pi;
int n;
int connect[501];
int total[501];
int cost[501];
vector<int> need[501];

int main() {
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		connect[i] = 0;
		total[i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
		while (true) {
			int input;
			cin >> input;
			if (input == -1)
				break;
			need[input].push_back(i);
			connect[i]++;
		}
	}


	// 큐는 (비용, 건물 번호) 순서.
	queue<pi> q;

	// 차수가 0인 건물 push
	for (int i = 1; i <= n; i++) {
		if (connect[i] == 0) {
			q.push({ cost[i],i });
		}
	}
	
	while (!q.empty()) {
		int c = q.front().first;
		int from = q.front().second;
		q.pop();

		// 연결된 건물의 총 시간 수정.
		for (int i = 0; i < need[from].size(); i++) {
			int to = need[from][i];
			connect[to]--;
			total[to] = max(total[to], total[from] + c);
			if (connect[to] == 0)
				q.push({ cost[to],to });
		}
	}


	for (int i = 1; i <= n; i++) {
		cout << total[i]+cost[i] << endl;
	}
	return 0;
}