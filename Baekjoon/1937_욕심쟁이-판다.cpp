// 백준 1937번 욕심쟁이 판다

/*
처음엔 bfs+dp로 풀어서 시간초과

dp 메모이제이션으로 풀이해서 해결.
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, answer;
int map[500][500];
int dp[500][500];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

// dp.
int dfs(int x, int y) {
	int& ret = dp[x][y];

	if (ret != -1)
		return ret;

	ret = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n || map[nx][ny] <= map[x][y])
			continue;

		ret = max(ret, 1 + dfs(nx, ny));
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			cin >> map[i][j];

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			dfs(i, j);
		
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			answer = max(answer, dp[i][j]);

	cout << answer;

	return 0;
}