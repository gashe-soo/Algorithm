// 백준 3980번 선발 명단

/*
11명을 배치하는 경우는 최대 11! => 약 4천만 = 1초 안에 가능
+
모든 선수가 모든 포지션에 대해 능력치가 있는 것이 아니므로 사실은 더 짧음

*/

#include <iostream>
#define SIZE 11
using namespace std;

int player[SIZE][SIZE];
int answer;
bool v[SIZE];

void dfs(int cnt, int val) {
	if (cnt == 11) {
		answer = answer > val ? answer : val;
		return;
	}
	for (int i = 0; i < SIZE; i++) {
		if (!v[i] && player[cnt][i] !=0) {
			v[i] = true;
			dfs(cnt + 1, val + player[cnt][i]);
			v[i] = false;
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		answer = 0;
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				cin >> player[i][j];
			}
		}
		dfs(0, 0);
		cout << answer << "\n";
	}
	

	return 0;
}