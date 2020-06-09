#include <iostream>
#include <algorithm>

// 백준 1637 날카로운 눈

using namespace std;

// 1. 나온 수 누적으로 확인, 짝수면 이후에 홀수 존재/ 홀수면 이전에 홀수 존재
// 2. 수의 범위를 이분탐색으로 확인.

int n, x;
long long a[20001], b[20001], c[20001];

// 1.
long long count(long long k) {
	long long ans = 0;
	for (int i =0; i < n; i++) {
		if(k>=a[i])
			ans += (min(k, c[i]) - a[i]) / b[i] + 1;	// 식은 풀이 참고함.
	}
	return ans;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> c[i] >> b[i];	
	}
	long long left = 1, right = 2147483647;
	// 2.
	while (left < right) {
		long long mid = (left + right) / 2;
		if (count(mid)% 2==0) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	if (left == 2147483647) {
		cout << "NOTHING";
	}
	else {
		cout << left << " " << count(left) - count(left - 1);
	}

	return 0;
}