// 백준 1342번 행운의 문자열

/*
백트래킹.
10!이지만 인접한지 확인하기 위한 시간+ set,map 탐색 시간이 걸리기에 시간초과 발생
따라서 가능한지 확인하고 중복 경우만 제거
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <cstring>

using namespace std;

int n,ans;
string str;
bool v[10];
unordered_map<char,int> m;

bool lucky(string s) {
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1]) return false;
	}
	return true;
}

void solve(string s) {
	if (s.length() == n) {
		if (lucky(s)) {
			ans++;
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		if (v[i] || s[s.length() - 1] == str[i]) continue;
		v[i] = true;
		solve(s + str[i]);
		v[i] = false;
	}
	return;
}

int fac(int x) {
	int ret = 1;
	for (int i = 2; i <= x; i++)
		ret *= i;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> str;
	n = str.length();
	
	for (int i = 0; i < n; i++) {
		m[str[i]]++;
	}

	for (int i = 0; i < n; i++) {
		memset(v, 0, sizeof(v));
		v[i] = true;
		solve(string(1, str[i]));
	}

	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second > 1)
			ans = ans / fac(it->second);
	}
	cout<<ans;

	
	return 0;
}