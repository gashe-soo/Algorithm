// 백준 1062번 가르침

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
string word[51];
bool v[26];

int answer;

void solve(int now, int cnt) {
	if (cnt == k) {
		int val = 0;
		for (int i = 0; i < n; i++) {
			bool flag = true;
			for (int j = 0; j < word[i].size(); j++) {
				int cur = word[i][j] - 'a';
				if (!v[cur]) {
					flag = false;
					break;
				}
			}
			if (flag)
				val++;
		}
		answer = max(answer, val);
		return;
	}

	for (int i = now; i < 26; i++) {
		if (!v[i]) {
			v[i] = true;
			solve(i, cnt + 1);
			v[i] = false;
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	if (k < 5) {
		cout << 0;
		return 0;
	}
	else if (k == 26) {
		cout << n;
		return 0;
	}
	k -= 5;
	string t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		t = t.substr(4, t.size() - 8);
		word[i] = t;
	}
	v[0] = v[2] = v['i' - 'a'] = v['n' - 'a'] = v['t' - 'a'] = 1;

	answer = 0;
	solve(0,0);
	cout << answer;
	return 0;
}