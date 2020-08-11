// 백준 5052번 전화번호 목록

/*
정렬하고 모든 원소가 앞뒤로 접두사가 아니라면 접두사가 없는 것이다. 
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string num[10001];
int pos[11];

bool contain(string a, string b) {
	int size = a.length() > b.length() ? b.length() : a.length();

	for (int i = 0; i < size; i++) {
		if (a[i] != b[i])
			return false;
	}
	return true;
}

void solve(){
	sort(num, num + n);
	for (int i = 0; i < n-1; i++) {
		if (contain(num[i], num[i + 1])) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}

		solve();

	}


	return 0;
}