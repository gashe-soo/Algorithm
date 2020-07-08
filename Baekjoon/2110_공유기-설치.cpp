// 백준 2110번 공유기 설치

// 1. 이분탐색

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> c;
	
	vector<int> v(n);
	for (int i = 0; i < n; i++) 
		cin >> v[i];

	sort(v.begin(), v.end());
    int ans =0, d=0;
	int left = 1, right = v[n - 1] - v[0];
    while (left <= right) {
        int mid = (left + right) / 2; // 기준
        int start = v[0];
        int cnt = 1;

        for (int i = 1; i < n; i++) {
            d = v[i] - start;
            if (mid <= d) {
                ++cnt;
                start = v[i];
            }
        }

        if (cnt >= c) {
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << ans;
	return 0;
}