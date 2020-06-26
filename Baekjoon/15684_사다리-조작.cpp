#include <iostream>

// 백준 15684번 사다리 조작

using namespace std;

// 1. 가능한 사다리를 모두 놓기
// 1-1. 사다리를 놓더라도 일정 방향으로 놔둬야 중복을 줄일 수 있다.
// 1-2. 같은 열에 둔다면 이전에 둔 행보다는 아래 행에 놔둔다. 열은 그대로 확인.
// 2. 사다리 결과 확인


int n, m, h;
int ladder[31][11];
int answer;

// 2.
bool check() {
	for (int i = 1; i <= n; i++) {
		int y = i;
		for (int j = 1; j <= h; j++) {
			if (ladder[j][y] == 1)
				y++;
			else if (ladder[j][y] == 0) {
				if(ladder[j][y-1] == 1)
					y--;
			}
		}
		if(y !=i) return false;
	}
	return true;
}
// 1. 일정한 방향으로 두며 가능한 조합 확인
void go(int x, int cnt) {
	if (check()) {
		answer = answer > cnt ? cnt : answer;
		return;
	}
	if (cnt == 3)
		return;
	for (int i = x; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (ladder[i][j-1] == 0 && ladder[i][j] == 0 && ladder[i][j + 1] == 0) {
				ladder[i][j] = 1;
				go(i,cnt + 1);
				ladder[i][j] = 0;
			}
		}
	}
	return;
}


int main() {
	cin >> n >> m >> h;
	for (int i = 0; i <= h; i++) {
		for (int j = 0; j <= n; j++) {
			ladder[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		ladder[x][y] = 1;
	}
	answer = 4;
	go(1,0);
	if (answer == 4) cout << "-1";
	else cout << answer;
	return 0;
}