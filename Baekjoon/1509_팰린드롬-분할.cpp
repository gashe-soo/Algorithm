// 백준 1509번 팰린드롬 분할

/*
dp로 해결.
palin[s][e] = [s,e]구간의 palindrome 여부
*/

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

string str;
bool palin[2501][2501];
int dp[2501];
int val[5001];
string s;
int n;

int dp1() {
	for (int i = 0; i < n; i++) {
		palin[i][i] = 1;
		for (int j = 0; j < n; j++) {
			if (j == i + 1 && str[i] == str[j])
				palin[i][j] = 1;
		}
	}

	for (int i = 2; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			if (palin[j + 1][j + i - 1] && str[j] == str[j + i])
				palin[j][j + i] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		dp[i] = 2501;
		for (int j = 0; j <= i; j++) {
			if (palin[j][i]) {
				dp[i] = min(dp[i], dp[j - 1] + 1);
			}
		}
	}
	return dp[n - 1];
}

void manacher() {
	
	for (int i = 0; i < n; i++) {
		s += '#';
		s +=str[i];
	}
	s += '#';
	int r = 0, p = 0;
	for (int i = 0; i < s.length(); i++) {
		if (i <= r)
			val[i] = min(val[2 * p - i], r - i);
		else
			val[i] = 0;

		while (i - val[i] - 1 >= 0 && i + val[i] + 1 < s.length() && s[i - val[i] - 1] == s[i + val[i] + 1])
			val[i]++;

		if (r < i + val[i]) {
			r = i + val[i];
			p = i;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> str;
	n = str.length();
	
	manacher();

	
	cout << dp1();
	
	return 0;
}
