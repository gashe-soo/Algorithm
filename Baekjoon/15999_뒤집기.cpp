// 백준 15999번 뒤집기

/*
같은 색으로 연결되어 있으면 색이 뒤집힌다.
그렇지만 색이 다른 블록으로 둘러 쌓이면 인접하지 않은 블록은 색이 바뀌지 않는다.
=> 인접하지 않은 블록의 개수를 세서 개수만큼 2를 곱한다.
*/

#include <iostream>
#include <cmath>

using namespace std;

int n, m;
char board[2001][2001];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
const int NUM = 1e9 + 7;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	
	int cnt = n*m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k], ny = j + dy[k];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (board[nx][ny] != board[i][j]) {
					cnt--;
					break;
				}
			}
		}
	}
	
	int ans = 1;
	for (int i = 0; i < cnt; i++) {
		ans *= 2;
		ans %= NUM;
	}
	cout << ans;

	return 0;
}