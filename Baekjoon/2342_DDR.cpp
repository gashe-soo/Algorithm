// 백준 2342번 Dance Dance Revolution

/*
dp
dp[수열 인덱스][왼발][오른발]로 dp확인

*/


#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> arr;
int d[5] = { 0,3,4,1,2 };
int dp[100001][5][5];
int answer = 987654321;

int score(int a, int num) {
	if (a == 0) return 2;
	if (a == num) return 1;
	if (a == d[num]) return 4;
	return 3;
}

int solve(int i, int left, int right) {
	if (i == arr.size()) return 0;
	int& ret = dp[i][left][right];

	if (ret != -1) return ret;
	
	ret = 987654321;

	if (arr[i] != right) {
		int cost = score(left, arr[i]);
		ret = min(ret, cost + solve(i + 1, arr[i], right));
	}
	if (arr[i] != left) {
		int cost = score(right, arr[i]);
		ret = min(ret, cost + solve(i + 1, left, arr[i]));
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(dp, -1, sizeof(dp));
	while (true) {
		int num;
		cin >> num;
		if (num == 0)
			break;
		else
			arr.push_back(num);
	}
	
	int ans = solve(0, 0, 0);
	cout << ans;

	return 0;
}