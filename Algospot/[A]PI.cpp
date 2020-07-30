// Algospot PI

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

string str;
int n;
int dp[10001];

int get(int start, int L) {
	string s = str.substr(start, L);
	if (s == string(s.size(), s[0])) return 1;
	bool flag = true;
	for (int i = 1; i < L; i++) {
		if (s[i] - s[i - 1] != s[1] - s[0])
			flag = false;
	}
	if (flag) {
		if (abs(s[1] - s[0]) == 1) return 2;
		
	}
	bool flag2 = true;
	for (int i = 0; i < L-2; i++) {
		if (s[i] != s[i + 2])
			flag2 = false;
	}
	if (flag2) return 4;
	if (flag) return 5;

	return 10;
}

int solve(int start) {
	if (start == n) return 0;
	int& ret = dp[start];

	if (ret != -1) return ret;

	ret = 987654321;

	for (int L = 3; L <= 5; L++) {
		if (start + L <= n) {
			ret = min(ret, solve(start + L) + get(start, L));
		}
	}
	return ret;
}



int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	
	while (tc--) {
		memset(dp, -1, sizeof(dp));
		cin >> str;
		n = str.length();

		cout << solve(0) << "\n";
	}
	return 0;
}