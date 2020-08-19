// 백준 2931번 가스관

/*
1. bfs든 dfs든 해서 모든 가스관에 가스가 가는 지 확인
2. 만약 없어진 블록을 만났을 경우 4방향 중 이미 방문한 블록 제외 어떤 방향과 연결되는지를 확인

*/

#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> pi;
int r, c;
char euro[25][25];
bool v[25][25];
pi mos;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
map<char, pi> m;
// 상하좌우로 연결될 때 가능한 리스트
char d[4][4] = { {'|','+','1','4'},{'|','+','2','3'},{'-','+','1','2'},{'-','+','3','4'} };

// 제거된 블록일 때의 4방향 중 연결된 경우에 따라 기존 블록이 무엇이었는지 판단.
char block(vector<int> arr) {
	if (arr.size() == 0) return '.';
	if (arr.size() == 4) return '+';
	if (arr[0] == 0) {
		if (arr[1] == 1) return '|';
		if (arr[1] == 2) return '3';
		if (arr[1] == 3) return '2';
	}
	if (arr[0] == 1) {
		if (arr[1] == 2) return '4';
		if (arr[1] == 3) return '1';
	}
	return '-';
}

// 들어온 방향에 따라서 나갈 방향 정해준다.
pi getPi(pi node) {
	int x = node.first, y = node.second;
	if (euro[x][y] == '|') {
		if (v[x - 1][y]) return { x + 1,y };
		else return { x - 1,y };
	}
	if (euro[x][y] == '-') {
		if (v[x][y - 1]) return { x,y + 1 };
		return { x,y - 1 };
	}
	
	if (euro[x][y] == '1') {
		if (v[x][y + 1]) return { x + 1,y };
		return { x,y + 1 };
	}
	if (euro[x][y] == '2') {
		if (v[x - 1][y]) return { x,y + 1 };
		return { x - 1,y };
	}
	if (euro[x][y] == '3') {
		if (v[x][y - 1]) return { x - 1,y };
		return { x,y - 1 };
	}
	if (euro[x][y] == '4') {
		if (v[x][y - 1]) return { x + 1,y };
		return { x,y - 1 };
	}
}

// bfs
void bfs() {
	queue<pi> q;
	
	q.push(mos);
	v[mos.first][mos.second] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (euro[x][y] == 'M') {
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c || euro[nx][ny]=='.') continue;
				q.push({ nx,ny });
				v[nx][ny] = true;
			}
		}
		// 제거된 블록 만나면 블록 모양 판단해서 출력 후 함수 종료.
		else if (euro[x][y] == '.') {
			vector<int> arr;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				for (int j = 0; j < 4; j++) {
					if (euro[nx][ny] == d[i][j]) arr.push_back(i);
				}
			}
			cout << x+1 << " " << y+1 << " " << block(arr);
			return;
		}
		// '+' 모양이면 4방향 모두 들어가기.
		else if (euro[x][y] == '+') {
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (v[nx][ny]) continue;
				q.push({ nx,ny });
				v[nx][ny] = true;
			}
		}
		// 블록 모양에 따라 다음 방향 정하기.
		else {
			pi node = getPi({ x,y });
			int nx = node.first, ny = node.second;
			if (v[nx][ny]) continue;
			q.push(node);
			v[nx][ny] = true;
		}
	}
	return;
}



int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> euro[i][j];
			if (euro[i][j] == 'M') mos = { i,j };
		}
	}
	bfs();
	return 0;
}