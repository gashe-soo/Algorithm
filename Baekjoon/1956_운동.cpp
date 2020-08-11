// 백준 1956번 운동

/*

플로이드 와샬.
V가 400이라 V^3 가능.

*/

#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int map[401][401];
int v, e;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> v >> e;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j) map[i][j] = 0;
			else map[i][j] = INT_MAX;
		}
	}

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = min(map[a][b], c);
	}

	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (map[i][k] == INT_MAX || map[k][j] == INT_MAX) continue;
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}

	int answer = INT_MAX;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			
			if (i==j || map[i][j] == INT_MAX || map[j][i] == INT_MAX) continue;
			answer = min(answer, map[i][j] + map[j][i]);
		}
	}

	if (answer == INT_MAX) 
		cout << "-1";
	else {
		cout << answer;
	}

	
	return 0;
}