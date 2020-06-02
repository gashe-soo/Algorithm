#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int b[50][50];
int N, M, r, c, direction;
int answer;
int dx[4] = { 0, -1, 0, 1 };	// 좌, 상, 우, 하 (상,우,하,좌 의 왼쪽)
int dy[4] = { -1, 0, 1, 0 };
int rx[4] = { 1, 0 , -1, 0 };
int ry[4] = { 0, -1, 0, 1 };


void dfs(int x, int y, int d) {
	//1. 청소
	if (b[x][y] == 0) {
		answer++;
		b[x][y] = 2;
	}
	//2. 방향 탐색
	int w = d;
	int nx = x + dx[w];
	int ny = y + dy[w];
	int time = 4;

	// 왼쪽이 청소를 안 했는 지 확인, 안 비었다면 그쪽 방향으로 돌리기  / 반복
	while (nx <= 0 || nx >= N - 1 || ny <= 0 || ny >= M - 1 || b[nx][ny] != 0) {
		time--;
		if (w == 0) w = 3;
		else w--;
		nx = x + dx[w];
		ny = y + dy[w];
		if (time== 0)
			break;
	}
	if (w == 0) w = 3;
	else w--;
	//a. 왼쪽 청소 안 했을때
	if (time == 4) {
		dfs(nx, ny, w);
	}//b. 4방향 중 청소 안한 곳이 있을 때
	else if (time > 0) {
		dfs(nx, ny, w);
	}
	else{	// 후퇴
		nx = x + rx[d]; 
		ny = y + ry[d];
		//c. 벽이 없다면
		if (b[nx][ny] != 1)
			dfs(nx, ny, d);
		else // 벽이라면
			return;
	}
	return;

}


int main() {
	cin >> N >> M;
	cin >> r >> c >> direction;
	answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> b[i][j];
		}
	}
	dfs(r, c, direction);
	cout << answer;
	return 0;
}