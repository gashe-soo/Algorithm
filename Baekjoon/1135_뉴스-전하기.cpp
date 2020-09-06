// 백준 1135번 뉴스 전하기

/*
dp와 dfs의 중간 그 어딘가..?

풀이 :
1. 서브트리가 소요되는 시간 중 큰 시간부터 전화돌리기
2. 서브트리 소요 시간 계산
	2-1. 서브트리가 없으면 0 return.
	2-2. 서브트리가 있으면 정렬해서 그 중 최소로 소요되는 시간 찾기.
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;
int n;
vector<int> p[51];
int dp[51];	// n번이 본인 직+간접 부하에게 돌리는 데 사용되는 시간 (서브트리 모두 돌리는 데 사용되는 시간 중 최소)

bool cmp(int a, int b) {
	return dp[a] > dp[b];
}

int solve(int num) {
	int& ret = dp[num];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i < p[num].size(); i++) {
		int to = p[num][i];
		solve(to);
	}
	
	sort(p[num].begin(), p[num].end(), cmp);
	ret =0 ;
	for (int i = 0; i < p[num].size(); i++) {
		int to = p[num][i];
		ret = max(ret, i + 1 + dp[to]);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		int u;
		cin >> u;
		if (u == -1) continue;
		p[u].push_back(i);
	}
	cout<<solve(0);

	return 0;
}