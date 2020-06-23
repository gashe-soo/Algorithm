#include <iostream>
#include <queue>
#include <string>

//백준 2178번 미로 탐색

using namespace std;

// 보자마자 생각난건 다익스트라 알고리즘
// 하지만 bfs로도 풀 수 있을 것 같아, bfs로 풀었다. 
// 하지만 다익스트라도 버릴 수 없어 혼합된 형태의 알고리즘 작성.

typedef pair<int, int> pi;
int map[100][100];
int dist[100][100];
int n, m;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int bfs() {
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	dist[0][0] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny]==0)
				continue;
			if (dist[nx][ny] > dist[x][y] + 1) {
				dist[nx][ny] = dist[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}

	return dist[n - 1][m - 1];
}


int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j]-'0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j] = 987654321;
		}
	}
	cout << bfs() << endl;
	return 0;
}