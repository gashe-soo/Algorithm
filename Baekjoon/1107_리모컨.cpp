#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

// 백준 1107 리모컨

using namespace std;

// 1. 현재 있는 숫자 가지고 조합 가능한 모든 수 확인.
// 2. 0부터 백만까지 돌면서 리모컨 최소횟수 확인
// 시간복잡도: O(nlogn)

bool num[10];
vector<int> v;

// 1.
void count(int n) {
	int x = n;

	if (x == 0) {
		if (num[x]) return;
		v.push_back(n);
	}
	// 현재 숫자로 조합 중.
	while (x > 0) {
		if (num[x % 10]) return;
		x /= 10;
	}
	v.push_back(n);
}

int main() {
	memset(num, 0, sizeof(num));
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int idx;
		cin >> idx;
		num[idx] = true;
	}
	for (int i = 0; i < 1000000; i++) {
		count(i);
	}
	// 현재 100번인 상태에서 시작.
	int answer = abs(n - 100);

	// 나머지 숫자 확인.
	for (int val : v) {
		int cnt = to_string(val).length() + abs(val - n);
		answer = answer > cnt ? cnt : answer;
	}

	cout << answer;

	return 0;
}
