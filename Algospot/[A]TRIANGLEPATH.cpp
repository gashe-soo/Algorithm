// Algospot TrianglePath

// DP memoization
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int arr[101][101];
int dp[101][101];

int solve(int x, int y) {
	if (x == n - 1) return arr[x][y];

	int& ret = dp[x][y];

	if (ret != -1) return ret;
	return ret = max(solve(x + 1, y), solve(x + 1, y + 1)) + arr[x][y];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		memset(dp, -1, sizeof(dp));
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j =0; j <= i;j++) {
				cin >> arr[i][j];
			}
		}

		cout << solve(0, 0)<<"\n";
	}


	return 0;
}