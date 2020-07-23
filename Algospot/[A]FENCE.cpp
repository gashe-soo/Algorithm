// Algospot Fence

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> square(20000, 10001);

// 정석 풀이
int solve(int left, int right) {
	if (left == right) return square[left];

	int mid = (left + right) / 2;
	int ret = max(solve(left, mid), solve(mid + 1, right));

	int lo = mid, hi = mid + 1;
	int height = min(square[lo], square[hi]);
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

// min값 기준으로 나누기.
int size(int left, int right) {
	if (left==right) return square[right];
	auto it = min_element(square.begin()+left, square.begin() + right+1);
	int ret = *it * (right - left + 1);
	
	int before, after;
	if (it - square.begin() == left) 
		before = square[left];
	else
		before = size(left, it - square.begin() - 1);
	

	if (it - square.begin() == right) 
		after = square[right];
	else 
		after = size(it - square.begin() + 1, right);
	
	
	return max({ ret,before,after });	
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;

	while (tc--) {
		cin >> n;
		
		for (int i = 0; i < n; i++) {
			cin >> square[i];
		}
		cout << solve(0,n-1) << '\n';


	}


	return 0;
}