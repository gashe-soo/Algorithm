#include <iostream>
#include <cstring>

// 백준 2602 돌다리 건너기

using namespace std;

string target;
string bridge[2];
int dp[2][101][21];

int count(int b, int idx, int cnt) {
	if (cnt == target.length())
		return 1;

	if (dp[b][idx][cnt] > -1)
		return dp[b][idx][cnt];

	int ret = 0;
	for (int i = idx; i < bridge[b].length(); i++) {
		if (target[cnt] == bridge[b][i]) {
			ret += count(1 - b, i + 1, cnt + 1);
		}
	}
	return dp[b][idx][cnt] =  ret;
}


int main() {
	cin >> target;
	for (int i = 0; i < 2; i++) {
		cin >> bridge[i];
	}
	memset(dp, -1, sizeof(dp));
	int answer = 0;
	for (int i = 0; i < 2; i++) {
		int result = count(i, 0, 0);
		answer += result;
	}
	cout << answer;

}


