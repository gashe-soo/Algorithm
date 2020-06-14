#include <iostream>
#include <algorithm>
#include <vector>

// 백준 2352번 반도체 설계

using namespace std;

// 0. LIS알고리즘 => DP => 시간 초과
// 1. 이분탐색

int val[40000];

int main() {
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> val[i];
	}
	arr.push_back(val[0]);

	for (int i = 1; i < n; i++) {
		int idx = arr.size() - 1;
		// 만약 배열의 마지막 원소보다 값이 크다면
		if (val[i] > arr[idx])
			arr.push_back(val[i]);
		// 그렇지 않다면 자리 찾기.
		else {
			int left = 0, right = idx;
			while (left < right) {
				int mid = (left + right) / 2;
				if (val[i] > arr[mid]) 
					left = mid + 1;
				else 
					right = mid;
			}
			arr[right] = val[i];
		}
	}

	cout << arr.size() << endl;

	
	
	return 0;
}