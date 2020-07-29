// Algospot LIS

// DP or BinarySearch

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n, arr[500];

// dp O(n^2)
int dp() {
	int ret = 0;
	int s[501];
	for (int i = 0; i < n; i++) s[i] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i])
				s[i] = max(s[i], s[j] + 1);
		}
	}
	
	for (int i = 0; i < n; i++) {
		ret = max(ret, s[i]);
	}
	return ret;
}

// ÀÌºÐÅ½»ö O(nlogn)
int bs() {
	vector<int> s;
	s.push_back(arr[0]);

	for (int i = 1; i < n; i++) {
		if (arr[i] > s.back())
			s.push_back(arr[i]);
		else {
			int idx = lower_bound(s.begin(), s.end(), arr[i]) - s.begin();
			s[idx] = arr[i];
		}
	}
	return s.size();
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i];
		cout << dp() << "\n";
		//cout << bs() << "\n";
	}

	return 0;
}