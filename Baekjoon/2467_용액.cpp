// 백준 2467번 용액

// 투포인터

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
pair<int, int> ret;
int liquid[100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> liquid[i];

	int left = 0, right = n - 1;
	int val = abs(liquid[left] + liquid[right]);
	ret = { liquid[left],liquid[right] };
	while (left < right) {

		if (abs(liquid[left] + liquid[right]) < abs(val)) {
			val = liquid[left] + liquid[right];
			ret = { liquid[left],liquid[right] };
		}
		if (liquid[left] + liquid[right] > 0)
			right--;
		else
			left++;
	}

	
	cout << ret.first << " " << ret.second;


	return 0;
}