// 백준 2239번 스도쿠

/*
백트래킹.
중요한 건 행,열, 3x3 확인해도 안되면 끝내야 한다.

*/

#include <iostream>
#include <string>
using namespace std;

bool v[9][10][2];
bool kan[3][3][10];
int map[9][9];
int zero;

void sudoku(int cnt, int x) {
	if (cnt == zero) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j];
			}
			cout << "\n";
		}
		exit(0);
	}
	
	for (int i = x; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (map[i][j] != 0) continue;
			for (int k = 1; k <= 9; k++) {
				if (!v[i][k][0] && !v[j][k][1] && !kan[i/3][j/3][k]) {
					v[i][k][0] = v[j][k][1] = kan[i / 3][j / 3][k] = true;
					map[i][j] = k;
					sudoku(cnt + 1, i);
					map[i][j] = 0;
					v[i][k][0] = v[j][k][1] = kan[i / 3][j / 3][k] = false;
				}
			}
			if (map[i][j] == 0)	// 문제의 핵심.
				return;
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string str;
	zero = 0;
	for (int i = 0; i < 9; i++) {
		cin >> str;
		for (int j = 0; j < 9; j++) {
			int val = str[j] - '0';
			map[i][j] = val;
			if (val != 0)
				v[i][val][0] = v[j][val][1] = kan[i / 3][j / 3][val] = true;
			else zero++;
		}
	}

	sudoku(0, 0);
	return 0;
}