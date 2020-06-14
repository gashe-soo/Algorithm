#include <iostream>

// 백준 3085_사탕 게임

using namespace std;

int n;
char map[50][50];
int dx[2] = { 0,1 };
int dy[2] = { 1,0 };

void swap(int x, int y, int nx, int ny) {
	char temp = map[x][y];
	map[x][y] = map[nx][ny];
	map[nx][ny] = temp;
	return;
}
// 행,열 최대 연속 개수 확인
int check() {
	int ret = 0;

	for (int i = 0; i < n; i++) {
		int temp = 1;
		int cnt = 0;
		for (int j = 0; j < n - 1; j++) {
			
			if (map[i][j] == map[i][j + 1])
				temp++;
			else {
				cnt = cnt > temp ? cnt : temp;
				temp = 1;
			}
		}
		cnt = cnt > temp ? cnt : temp;
		ret = ret > cnt ? ret : cnt;
	}
	for (int i = 0; i < n; i++) {
		int temp = 1;
		int cnt = 0;
		for (int j = 0; j < n - 1; j++) {
			if (map[j][i] == map[j + 1][i])
				temp++;
			else {
				cnt = cnt > temp ? cnt : temp;
				temp = 1;
			}
		}
		cnt = cnt > temp ? cnt : temp;
		ret = ret > cnt ? ret : cnt;
	}
	return ret;
}

// 돌면서 오른쪽, 아래 원소랑 swap해서 연속 개수 확인
int change() {
	int ret = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 2; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < n && ny < n && map[i][j] != map[nx][ny]) {
					swap(i, j, nx, ny);
					int temp = check();
					ret = ret > temp ? ret : temp;
					swap(i, j, nx, ny);
				}
			}
		}
	}
	return ret;
}


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string al;
		cin >> al;
		for (int j = 0; j < n; j++) {
			map[i][j] = al[j];
		}
	}
	cout << change() << endl;




	return 0;
}