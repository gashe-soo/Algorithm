// 백준 1113번 수영장 만들기

/*
1. 가장자리는 고려대상 x
2. 높이 1부터 8까지 하나씩 확인
2-1. 높이 n인 칸을 출발점으로 같은 칸만 bfs로 확인
2-2. 만약 n인 칸이 가장자리에 해당한다면 이는 불가능하므로 원상복귀 후 return
2-3. 만약 n인 칸이 모두 조건에 부합한다면 해당 칸 1증가 + 칸 개수 확인.

*/

#include <iostream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

int n,m;
int swim[50][50];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool v[50][50];
int map[50][50];

int bfs(int x, int y, int val) {

	memset(v, 0, sizeof(v));
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) map[i][j] = swim[i][j];
	queue<pi> q;
	q.push({ x,y });
	v[x][y] = true;
	map[x][y] = swim[x][y] + 1;
	int ret = 1;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i], ny = b + dy[i];
			if (v[nx][ny] || swim[nx][ny] > val) continue;
			if (nx <= 0 || ny <= 0 || nx >= n - 1 || ny >= m - 1 || swim[nx][ny] < val) {
				return 0;
			}	
			q.push({ nx,ny });
			v[nx][ny] = true;
			map[nx][ny] = swim[nx][ny] + 1;
			ret++;
		}
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) swim[i][j] = map[i][j];
	return ret;
}


int solve() {
	if (n <= 2 || m <= 2) return 0;
	int ret = 0;
	for (int val = 1; val < 9; val++) {		
		for (int i = 1; i < n-1; i++) {
			for (int j = 1; j < m-1; j++) {
				if (val == swim[i][j]) {
					ret+= bfs(i, j, val);
				}
			}
		}
	}

	return ret;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			swim[i][j] = str[j] - '0';
		}
	}
	int ret = solve();
	cout << ret;
	return 0;
}
