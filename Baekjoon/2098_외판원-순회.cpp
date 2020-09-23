// 백준 2098번 외판원 순회

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int map[16][16];
int dp[16][1 << 16];

const int INF = 987654321;

int solve(int cur, int v) {
	if (v == (1 << n) - 1) {
		if (map[cur][0] != 0) {
			return map[cur][0];
		}
		return INF;
	}
	int& ret = dp[cur][v];

	if (ret != -1)
		return ret;

	ret = INF;
	for (int i = 0; i < n; i++) {
		if (v & (1 << i)) continue;
		if (map[cur][i] == 0) continue;
		ret = min(ret, solve(i, (v | (1 << i))) + map[cur][i]);
	}
	return ret;

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 1);

	return 0;
}