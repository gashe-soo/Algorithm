#include <iostream>
#include <string>
#include <vector>
#include <queue>

//백준 17244번 아맞다우산

using namespace std;

// 0. 다익스트라 + 백트래킹이라고 생각하였다.
// 1. S 부터 가능한 x을 거쳐 e로 들어가는 알고리즘 작성 
// 2. X가 가능한 모든 조합을 확인해 모든 값을 확인
// 3. 각 경로마다 최소 거리를 생각해서 다익스트라 작성
// 4. 모든 조합을 확인하지만 호출된 함수에서 값이 이미 answer보다 크다면 필요없으므로 return해서 백트래킹 이용.


char map[50][50];
int n, m;
pair<int, int> start, arrive;
vector<pair<int, int>> x;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int answer =987654321;

// 3. s는 경로 출발 e는 경로 도착. 즉 e-s사이의 최소 거리 계산.
int dfs(pair<int, int> s, pair<int, int>e) {
	queue<pair<int, int>> q;
	vector<vector<int>> dist(m, vector<int>(n, 987654321));
	q.push(s);
	dist[s.first][s.second] = 0;

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n || map[nx][ny] == '#')
				continue;
			if (dist[nx][ny] > dist[x][y] + 1) {
				dist[nx][ny] = dist[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
	return dist[e.first][e.second];
}

// 4. 백트래킹
void count(int cnt, int val, int last, vector<bool> check) {
	if (cnt == x.size()) {
		val += dfs(x[last], arrive);
		answer = answer > val ? val : answer;
		return;
	}
	// 이미 값이 크다면 더 할 필요 없음. 
	if (val > answer)
		return;
	// 조합
	for (int i = 0; i < x.size(); i++) {
		if (!check[i]) {
			check[i] = true;
			count(cnt + 1, val + dfs(x[last], x[i]), i, check);
			check[i] = false;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		string t;
		cin >> t;
		for (int j = 0; j < n; j++) {
			map[i][j] = t[j];
			if (t[j] == 'S')
				start = { i,j };
			if (t[j] == 'E')
				arrive = { i,j };
			if (t[j] == 'X')
				x.push_back({ i,j });
		}
	}
	// S부터 첫 X까지.
	for (int i = 0; i < x.size(); i++) {
		vector<bool> check(5, 0);
		int val = dfs(start, x[i]);
		check[i] = true;
		count(1, val, i, check);
	}
	// X가 없다면 S부터 E까지만 고려하면 된다.
	if (x.size() == 0) {
		answer = dfs(start, arrive);
	}
	cout << answer;
	return 0;
}