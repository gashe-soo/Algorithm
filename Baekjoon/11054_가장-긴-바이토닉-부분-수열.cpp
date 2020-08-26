// 백준 11054 가장 긴 바이토닉 부분 수열

// 단순히 LIS 양쪽 

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int arr[1001];
int up[1001], down[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		up[i] = down[i] = 1;
	}
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < i; j++) 
			if (arr[j] < arr[i])
				up[i] = max(up[i], up[j] + 1);

	for (int i = n - 1; i >= 0; i--) 
		for (int j = n - 1; j > i; j--) 
			if (arr[j] < arr[i])
				down[i] = max(down[i], down[j] + 1);
	

	int now = 0;
	for (int i = 0; i < n; i++) 
		now = max(now, up[i] + down[i]);
	
	cout << now - 1;

	return 0;
}