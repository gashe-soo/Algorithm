// 백준 6539번 상범 빌딩

/*
bfs로 해결
왜 4ms에서 안 주는지 모를 따름..
*/

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

typedef pair<int, vector<int>> pi;
int l, r, c;
char building[30][30][30];
vector<int> s, e;

int df[6] = { -1,1,0,0,0,0 };
int dx[6] = { 0,0,-1,1,0,0 };
int dy[6] = { 0,0, 0,0,-1,1 };
bool v[30][30][30];

int bfs() {
	queue<pi> q;
	
	memset(v, 0, sizeof(v));
	q.push({ 0,s });
	v[s[0]][s[1]][s[2]] = 1;

	while (!q.empty()) {
		int cost = q.front().first;
		int f = q.front().second[0], x = q.front().second[1], y= q.front().second[2];
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nf = f + df[i], nx = x + dx[i], ny = y + dy[i];
			if (nf < 0 || nf >= l || nx < 0 || nx >= r || ny < 0 || ny >= c || building[nf][nx][ny] =='#' || v[nf][nx][ny]) continue;
			if (nf == e[0] && nx == e[1] && ny == e[2]) return cost+1;
			
			v[nf][nx][ny] = 1;
			q.push({ cost + 1,{nf,nx,ny} });
			
		}
	}
	return -1;
}




int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while (true) {
		cin >> l >> r >> c;
		if (l == 0)
			break;
		string str;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				cin >> str;
				for (int k = 0; k < c; k++) {
					building[i][j][k] = str[k];
					if (str[k] == 'S')
						s = { i,j,k };
					else if (str[k] == 'E')
						e = { i,j,k };
				}
			}
		}
	
		int ans = bfs();
		
		if (ans == -1)
			cout << "Trapped!\n";
		else
			cout << "Escaped in "<<ans<<" minute(s).\n";
	}

	return 0;
}