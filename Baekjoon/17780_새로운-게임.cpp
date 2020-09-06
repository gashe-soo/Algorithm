// 백준 17780번 새로운 게임 

/*
그냥 구현 문제
*/

#include <iostream>
#include <vector>

using namespace std;

struct Horse {
	int num, x, y, dir;
};

typedef pair<int, int> pi;
int n, k;
int board[13][13];
pi pos[11];	// n번째 말의 위치
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

vector<Horse> h[13][13];	// (i,j)에 있는 말

// 방향 바꾸기
int change(int dir) {
	if (dir == 0) return 1;
	if (dir == 1) return 0;
	if (dir == 2) return 3;
	if (dir == 3) return 2;
}

// 말 이동시 턴 오버되면 false, 유지되면 true 반환
bool go(int x, int y, int idx, int dir) {
	int nx = x + dx[dir], ny = y + dy[dir];
	// 나가거나, 파란색일때
	if (nx <= 0 || nx > n || ny <= 0 || ny > n || board[nx][ny] == 2) {
		int ndir = change(dir);
		int nnx = x + dx[ndir], nny = y + dy[ndir];
		h[x][y][0].dir = ndir;
		// 반대 방향도 파란색일때
		if (board[nnx][nny] == 2) {
			return true;
		}
		else {
			// 파란색이 아닐땐 재귀
			if (!go(x, y, idx, ndir))
				return false;
			return true;
		}
	}
	// 흰 색일때
	else if (board[nx][ny] == 0) {
		// 정방향 넣어주기
		for (int i = 0; i < h[x][y].size(); i++) {
			h[nx][ny].push_back(h[x][y][i]);
			int now = h[x][y][i].num;
			pos[now] = { nx,ny };		// 말 위치 동기화
		}
		h[x][y].clear();
		return h[nx][ny].size() < 4;
	}
	// 빨간 색일 때
	else {		
		// 역방향 넣어주기
		for (int i = h[x][y].size()-1; i >=0; i--) {
			h[nx][ny].push_back(h[x][y][i]);
			int now = h[x][y][i].num;
			pos[now] = { nx,ny };
		}
		h[x][y].clear();
		return h[nx][ny].size() < 4;

	}

}

int turn(int cnt) {
	// 1번 말부터 이동
	for (int i = 1; i <= k; i++) {
		int x = pos[i].first, y = pos[i].second;
		// i번째 말이 해당 위치에서 제일 아래에 있는 말이 아니라면 pass
		if (h[x][y][0].num != i)
			continue;
		int dir = h[x][y][0].dir;
		// 턴오버시 턴 숫자 return
		if (!go(x, y, i, dir))
			return cnt;
	}
	
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];


	for (int i = 1; i <= k; i++) {
		int x, y, dir;
		cin >> x >> y >> dir;
		h[x][y].push_back({ i,x,y,dir-1 });
		pos[i] = { x,y };
	}
	int answer = 0;
	bool flag = false;
	for (int i = 1; i <= 1000; i++) {
		answer = turn(i);
		if (answer) {
			flag = true;
			break;
		}
	}
	
	if (flag)
		cout << answer;
	else
		cout << -1;

	return 0;
}