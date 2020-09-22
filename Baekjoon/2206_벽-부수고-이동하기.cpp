// 백준 2206번 벽 부수고 이동하기

#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n, m;
int map[1001][1001];
int v[1001][1001][2];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int bfs() {
	queue<vector<int>> q;
	q.push({ 0,0,1 });
	v[0][0][1] = 1;
	
	while (!q.empty()) {
		vector<int> arr = q.front();
		int x = arr[0], y = arr[1], cnt = arr[2];
		q.pop();
		
		if (x == n - 1 && y == m - 1)
			return v[x][y][cnt];

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) 
				continue;
			if (cnt == 0 && map[nx][ny] == 1)
				continue;
			if (cnt && map[nx][ny] == 1) {
				q.push({ nx,ny,0 });
				v[nx][ny][0] = v[x][y][cnt] + 1;
			}
			else if (v[nx][ny][cnt] ==0 && map[nx][ny] == 0) {
				q.push({ nx,ny,cnt });
				v[nx][ny][cnt] = v[x][y][cnt] + 1;
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j] - '0';
		}
	}
	cout << bfs();

	return 0;
}