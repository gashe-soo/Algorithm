// 백준 10830번 행렬 제곱

/*
전형적인 분할 정복 문제

b가 1000억이라 메모이제이션을 해야하나 싶었지만 
단순히 재귀 호출로도 해결. 
시간초과는 똑같은 함수를 두 번 호출하는 것을 방지하여 해결.

*/

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> vec;
int n;
ll b;
vec arr;

// 행렬 계산
vec cal(vec a, vec b) {
	vec ret(n, vector<ll>(n, 0));
	vector<ll> tmp;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ll& t = ret[i][j];
			for (int k = 0; k < n; k++) {
				t += a[i][k] * b[k][j];
			}
			t = t % 1000;
		}
	}
	return ret;
}

// 재귀 호출
vec solve(vec a, ll num) {
	if (num == 1) return a;
	if (num % 2 == 0) {
		vec half = solve(a, num / 2); // 시간초과 방지
		return cal(half, half);
	}
	else {
		return cal(solve(a, num - 1), a);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> b;

	vector<ll> tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ll t;
			cin >> t;
			tmp.push_back(t);
		}
		arr.push_back(tmp);
		tmp.clear();
	}
	vec ret = solve(arr, b);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ret[i][j]%1000 << " ";
		}
		cout << "\n";
	}

	return 0;
}