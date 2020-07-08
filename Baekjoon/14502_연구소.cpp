// 백준 14502번 연구소

// 1. dfs + bfs합친 문제
// 2. dfs로 가능한 벽 세개 세우기
// 3. bfs로 조합마다 안전영역 확인

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> pi;
int answer, n, m;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

vector<pi> two;

// 3.
int bfs(vector<vector<int>> map) {
	queue<pi> q;
	vector<vector<bool>> visit(n, vector<bool>(m, 0));
	int ret = 0;
	for (auto p : two) {
		q.push(p);
		visit[p.first][p.second] = 1;
	}
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == 1 || visit[nx][ny]) continue;
			q.push({ nx,ny });
			map[nx][ny] = 2;
			visit[nx][ny] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) ret++;
		}
	}

	return ret;
}

// 2.
void go(int cnt, int x, vector<vector<int>> map, vector<vector<bool>> v) {
	if (cnt == 3) {
		int t = bfs(map);
		answer = answer > t ? answer : t;
		return;
	}
	for (int i = x; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 0 || v[i][j]) continue;
			v[i][j] = map[i][j] = 1;
			go(cnt + 1, i,map,v);
			v[i][j] = map[i][j] = 0;
		}
	}
	return;
}


int main() {
	cin >> n >> m;
	vector<vector<int>> map(n, vector<int>(m, 0));
	vector<vector<bool>> v(n, vector<bool>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int t;
			cin >> t;
			map[i][j] = t;
			if (t == 2) {
				two.push_back({ i,j });
			}
		}
	}
	go(0, 0, map,v);
	cout << answer;


	return 0;
}