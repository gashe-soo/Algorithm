// 백준 6209번 제자리 멀리뛰기

/*
지난번 풀었던 2110번 공유기 설치와 거의 유사한 문제.
출발점과 도착점 조건만 추가해서 해결.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d, m, n;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> d >> n >> m;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	
	int left = 0, right = d;
	int mid;
	int answer = 0;
	int x = 0;

	while (left <= right) {
		mid = (left + right) / 2;
		int cnt = 1;
		int start = 0;

		for (int i = 0; i < n; i++) {
			x = arr[i] - start;
			if (mid <= x) {
				cnt++;
				start = arr[i];
			}
		}
		if (mid <= d - start) {
			cnt++;
		}

		if (cnt >= n-m+2) {
			answer = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << answer;

	return 0;
}