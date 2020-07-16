// 백준 2151번 거울 설치

/*
처음에 잘못 생각해서 삽질.

다익스트라와 비슷하게 풀이하였다. 

첫 번째 문부터 두 번째 문까지 도달하는데 사용되는 거울의 개수를 거리라고 판단.

1. 방 문의 좌표를 저장
2. 좌표를 따라가며 거리 계산.
2-1. 좌표가  . # 일때는 온 방향대로 그대로 유지 
2-2. ! 일때는 이전 방향에서 바라봤을 때 총 3가지가 가능. 좌,우, 유지 => 이때는 이전의 거리와 비교하여 작을 경우만 큐에 푸쉬.
3. 방문 좌표 중에 가장 작은 값을 반환.
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, vector<int>> pp;

int n;
char home[50][50];
vector<pi> door;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int direction[4][2] = { {1,3},{2,0},{3,1},{0,2} };
int dist[50][50][4];
const int INF = 987654321;


int bfs() {
	queue<pp> q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < 4; k++)
				dist[i][j][k] = INF;

	for (int i = 0; i < 4; i++) {
		q.push({ i, {0, door[0].first, door[0].second} });
		dist[door[0].first][door[0].second][i] = 0;
	}

	while (!q.empty()) {
		int d = q.front().first;
		int c = q.front().second[0], x = q.front().second[1], y = q.front().second[2];
		q.pop();
		// 2-1. 좌표가  . # 일때는 온 방향대로 그대로 유지 
		if (home[x][y] == '.' || home[x][y] == '#') {
			int nx = x + dx[d], ny = y + dy[d];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n || home[nx][ny] == '*')
				continue;
			q.push({ d, {c,nx,ny} });
			dist[nx][ny][d] = c;
		
		}
		else {		// 2-2. ! 일때는 이전 방향에서 바라봤을 때 총 3가지가 가능. 좌,우, 유지 => 이때는 이전의 거리와 비교하여 작을 경우만 큐에 푸쉬.
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n || home[nx][ny] == '*')
					continue;
				int cost = d == i ? 0 : 1;

				if (dist[nx][ny][i] >= c + cost) {
					dist[nx][ny][i] = c + cost;
					q.push({ i, {c + cost,nx,ny} });
				}
			}
		}
		
	}
	int answer = INF;
	for (int i = 0; i < 4; i++) {		// 3. 방 문 간의 거리 중 거울의 최소 개수 확인
		answer = answer < dist[door[1].first][door[1].second][i] ? answer : dist[door[1].first][door[1].second][i];
	}
	
	return answer;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			home[i][j] = str[j];
			if (str[j] == '#') {
				door.push_back({ i,j });	// 1. 방 문의 좌표를 저장
			}
		}
	}
	cout << bfs();

	return 0;
}