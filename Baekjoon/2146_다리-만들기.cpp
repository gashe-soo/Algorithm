// 백준 2146번 다리 만들기

/*
1. bfs로 섬 구분
2. bfs로 섬끼리 연결.
2-1. 바다일 경우 상하좌우에 섬이 있는지 확인. 섬이 있다면 그 섬의 번호를 기준으로 bfs
2-2. 2-1의 섬의 번호가 아닐 경우, +값 리턴.

*/

#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pi> pp;
int n, cnt;
int map[100][100];
bool v[100][100];
int island[100][100];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs(int x, int y) {
	queue<pi> q;

	q.push({ x,y });
	v[x][y] = true;

	while (!q.empty()) {
		int a = q.front().first, b = q.front().second;
		q.pop();
		island[a][b] = cnt;
		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i], ny = b + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n || map[nx][ny] == 0 || v[nx][ny]) continue;
			q.push({ nx,ny });
			v[nx][ny] = true;
		}
	}
	return;

}

int check(int x, int y, int num) {
	queue<pp> q;
	memset(v, 0, sizeof(v));

	q.push({ 0,{ x,y } });
	v[x][y] = true;

	while (!q.empty()) {
		int d = q.front().first, i = q.front().second.first, j = q.front().second.second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = i + dx[k], ny = j + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n || v[nx][ny]) continue;
			if (island[nx][ny] != num && island[nx][ny] > 0)
				return d + 1;
			q.push({ d + 1,{nx,ny} });
			v[nx][ny] = true;
		}
	}
	return 987654321;

}




int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!v[i][j] && map[i][j] == 1) {
				bfs(i, j);
				cnt++;
			}
		}
	}
	int answer = 987654321;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k], ny = j + dy[k];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (island[nx][ny] > 0) {
						answer = min(answer, check(i, j, island[nx][ny]));
						break;
					}
				}
			}

		}
	}
	cout << answer;
	return 0;
}