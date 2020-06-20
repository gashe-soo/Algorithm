#include <iostream>
#include <vector>
#include <algorithm>

//백준 1920번 수 찾기

using namespace std;

int main() {
	// 입력속도 줄이기
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		bool flag = false;
		int left = 0, right = n;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (arr[mid] == num) {
				flag = true;
				break;
			}
			else if (arr[mid] > num) {
				right = mid - 1;
			}
			else
				left = mid + 1;
		}
		if (flag)
			cout << "1" << "\n";
		else
			cout << "0" << "\n";

	}

	return 0;
}