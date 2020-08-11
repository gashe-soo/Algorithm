// 백준 2252번 줄 세우기

/*
방향과 가중치가 있는 그래프이므로 위상 정렬을 사용

풀이: 위상 정렬
0. 배열 3개로 풀이
	앞에 서는 학생의 수: p 
	뒤에 서는 학생의 배열 : arr
	방문했는지 확인하는 배열 : v
1. a와 b를 입력받아 p[b] 증가, arr[a]에 b 추가
2. p[i]가 0인 경우 큐에 push
3. 연결된 간선을 삭제.
4. 연결되어 있던 노드의 p값이 0이 된다면 큐에 push

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int p[32001];
vector<int> arr[32001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	// 1.
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		p[b]++;
		arr[a].push_back(b);
	}
	queue<int> q;
	// 2.
	for (int i = 1; i <= n; i++) {
		if (p[i] == 0) 
			q.push(i);	
	}
	
	while (!q.empty()) {
		int from = q.front();
		q.pop();
		cout << from << " ";
		for (int i = 0; i < arr[from].size(); i++) {
			int to = arr[from][i];
			p[to]--;	// 3.
			// 4.
			if (p[to] == 0 )
				q.push(to);
		}
	}

	return 0;
}
