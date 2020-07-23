// 백준 6549번 히스토그램에서 가장 큰 직사각형

// 분할 정복

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<long long> square(100000, 1000000001);

long long solve(int left, int right) {
	if (left == right) return square[left];

	int mid = (left + right) / 2;
	long long ret = max(solve(left, mid), solve(mid + 1, right));

	int lo = mid, hi = mid + 1;
	long long height = min(square[lo], square[hi]);
	ret = max(ret, height * 2);

	while (left < lo || hi < right) {
		if (hi < right && (lo == left || square[lo - 1] < square[hi + 1])) {
			++hi;
			height = min(height, square[hi]);
		}
		else {
			--lo;
			height = min(height, square[lo]);
		}
		ret = max(ret, height * (hi - lo + 1));
	}
	return ret;
	
}


int main() {
    	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while (true) {
		cin >> n;
		if(n==0) break;
		for (int i = 0; i < n; i++) {
			cin >> square[i];
		}
		cout << solve(0,n-1) << '\n';


	}


	return 0;
}