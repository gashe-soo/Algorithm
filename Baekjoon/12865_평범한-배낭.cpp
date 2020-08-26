//백준 12865번 평범한 배낭

#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int w[101], v[101];
int dp[100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) 
		cin >> w[i] >> v[i];
	
	for (int i = 0; i < n; i++) {
		for (int j = k; j >= w[i]; j--) {
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	int ans = 0;
	for (int i = 0; i <= k; i++)
		ans = max(ans, dp[i]);

	cout << ans;

	

}