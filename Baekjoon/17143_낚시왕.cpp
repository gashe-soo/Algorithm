// ¹éÁØ 17143¹ø ³¬½Ã¿Õ

/*
´Ü¼ø ±¸Çö.

*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;
int r, c, m;
vector<vector<int>> map[101][101];
// up, down, right ,left;
int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,1,-1 };
int change[5] = { 0, 2, 1, 4, 3 };

bool cmp(vector<int> a, vector<int> b) {
	return a[0] > b[0];
}

void onlyOne() {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (map[i][j].size() > 1) {
				sort(map[i][j].begin(), map[i][j].end(), cmp);
				vector<int> tmp = map[i][j][0];
				map[i][j].clear();
				map[i][j].push_back(tmp);
			}
		}
	}
	return;
}

void move() {
	vector<pi> now;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (map[i][j].size() == 0) continue;
			now.push_back({ i,j });
		}
	}
	for (pi p : now) {
		int i = p.first, j = p.second;
		int d = map[i][j][0][2];
		int s = map[i][j][0][1];
		int z = map[i][j][0][0];
		int x = i, y = j;
		int mok = d > 2 ? c : r;
		mok = 2 * mok - 2;
		for (int k = 0; k < s%mok; k++) {

			int nx = x + dx[d], ny = y + dy[d];
			if (nx <= 0 || nx > r || ny <= 0 || ny > c) {
				d = change[d];
				nx = x + dx[d], ny = y + dy[d];
			}
			x = nx, y = ny;
		}

		map[x][y].push_back({ z,s,d });
		map[i][j].erase(map[i][j].begin());
	}

	onlyOne();

	return;
}



int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> r >> c >> m;
	
	for (int i = 0; i < m; i++) {
		int x, y, s, d, z;
		cin >> x >> y >> s >> d >> z;
		map[x][y].push_back({ z,s,d });
	}

	int answer = 0;
	int now = 0;
	while (now<=c) {
		now++;
		for (int i = 1; i <= r; i++) {
			if (map[i][now].size() == 1) {
				answer += map[i][now][0][0];
				map[i][now].clear();
				break;
			}
		}
		move();
	}
	cout << answer;


	return 0;
}