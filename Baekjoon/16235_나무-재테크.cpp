#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <algorithm>

 // 백준 16235번 나무 재테크

using namespace std;

// 0. 나이 어린 나무부터 양분 먹으므로 나이 어린 나무가 앞으로 와야 한다. => 우선순위 큐(시간 초과) => 덱의 앞 뒤 이용.
// 0-0. 위치별 나무 저장한 후, 정렬해서 덱에 저장.
// 1. 봄/여름 : 덱 돌면서 양분 먹고 나이 1 증가. 양분 못먹으면 dead에 나이/2 추가. 
// 2. 가을/겨울 : 나이 확인해서 주변 나무 심기
// 3. K번 반복.
// 4. 전체 나무 돌면서 덱의 사이즈 확인.


int n, m, k;
int A[11][11];
int map[11][11];
vector<int> temp[11][11];
deque<int> tree[11][11];
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

// 봄, 여름
void ss(int r, int c) {
	deque<int> d = tree[r][c];
	deque<int> newTree;
	int dead = 0;
	while (!d.empty()) {
		int t = d.front();
		d.pop_front();

		if (t <= map[r][c]) {
			map[r][c] -= t;
			newTree.push_back(t + 1);
		}
		else {
			dead += t / 2;
		}
	}
	map[r][c] += dead;
	tree[r][c] = newTree;
	return;
}
// 가을, 겨울
void fw(int r, int c) {
	deque<int> d = tree[r][c];
	while (!d.empty()) {
		int t = d.front();
		d.pop_front();
		if (t % 5 == 0) {
			for (int i = 0; i < 8; i++) {
				int nx = r + dx[i];
				int ny = c + dy[i];
				if (nx > 0 && nx <= n && ny>0 && ny<=n) {
					tree[nx][ny].push_front(1);
				}
			}
		}
	}
	map[r][c] += A[r][c];
	
	return;
}
// 초기 나무 나이별 정렬하여 덱에 저장.
void push() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sort(temp[i][j].begin(), temp[i][j].end());
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < temp[i][j].size(); k++) {
				tree[i][j].push_back(temp[i][j][k]);
			}
		}
	}
}
int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> A[i][j];
	
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		temp[x][y].push_back(z);
	}
	// 정렬
	push();

	// map 초기화
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			map[i][j] = 5;
	
	// k년
	while (k--) {
		// 모든 칸마다 봄,여름
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) 
				ss(i, j);
		// 가을, 겨울
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				fw(i, j);
	}
	int answer = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			answer += tree[i][j].size();

	cout << answer;
	

	return 0;
}