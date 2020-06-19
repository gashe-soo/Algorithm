#include <iostream>

// 백준 9095번 123더하기

using namespace std;

int main() {

	int tc;
	cin >> tc;

	int dp[12];
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	while (tc--) {
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}

	return 0;
}