#include <iostream>
#include <vector>

// 백준 1912번 연속 합

using namespace std;

int main() {

	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ans = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] <= arr[i - 1] + arr[i]) {
			arr[i] = arr[i - 1] + arr[i];	
		}
		ans = ans > arr[i] ? ans : arr[i];
	}

	cout << ans << endl;
	return 0;
}