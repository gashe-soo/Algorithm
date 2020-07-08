// 백준 16234번 인구 이동

// 1. 인구이동은 bfs로 확인.
// 1-1. 인구이동시 같은 연합은 벡터에 넣어서 나중에 평균으로 새로고침.

#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

typedef pair<int, int> pi;
int n, l, r;
int map[50][50];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int check[50][50];
bool v[50][50];

// 1.
bool bfs() {
	memset(check, 0, sizeof(check));
	memset(v, 0, sizeof(v));
	int cnt = 0;
	vector<pi> arr;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j]) continue;
			arr.clear();
			queue<pi> q;
			int sum = 0, size = 0;
			q.push({ i,j });
			v[i][j] = 1;
			
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				sum += map[x][y];
				size++;
				arr.push_back(q.front());
				q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i], ny = y + dy[i];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n || v[nx][ny]) continue;
					if (abs(map[nx][ny] - map[x][y]) < l || abs(map[nx][ny] - map[x][y]) > r) continue;
					q.push({ nx,ny });
					v[nx][ny] = 1;
				}
			}
			// 바로 계산해서 넣지 않으면 시간 초과.
			if (arr.size() > 1) {
				for (pi p : arr) {
					map[p.first][p.second] = sum / size;
				}
			}
			cnt++;
		}
	}
	

	return cnt != n * n;

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 0;
	while (bfs()) {
		ans++;
	}
	cout << ans;


	return 0;
}