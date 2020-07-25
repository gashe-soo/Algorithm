// Algospot JUMPMAN

#include <iostream>
#include <cstring>
using namespace std;

int n;
int map[100][100];
int v[100][100];

// 종만북 풀이 
int jump(int x, int y) {
	if (x >= n || y >= n) return 0;
	if (x == n - 1 && y == n - 1) return 1;
	int& ret = v[x][y];
	if (ret != -1) return ret;
	int size = map[x][y];
	return ret = jump(x + size, y) || jump(x, y + size);
}
// 내 풀이 . ( 종만북 풀이보다 4ms 느리다)
void dp(int x, int y) {
	int& ret = v[x][y];

	if (ret != -1)
		return;
	ret = 1;
	if (x + map[x][y] < n) {
		dp(x + map[x][y], y);
	}
	if (y + map[x][y] < n)
		dp(x, y + map[x][y]);
	return;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		memset(v, -1, sizeof(v));

		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				cin >> map[i][j];

		dp(0, 0);
		if (v[n - 1][n - 1] ==1)
			cout << "YES\n";
		else
			cout << "NO\n";
		
		/*if (jump(0, 0))
			cout << "YES\n";
		else cout << "NO\n";*/
	}


	return 0;
}