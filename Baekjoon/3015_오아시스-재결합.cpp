// 백준 3015번 오아시스 재결합

/*
스택 이용 => 분류 힌트 확인
+ 히스토그램(6549번)하고 비슷한 유형.

기본적인 조건이 A,B 사이에 A/B 둘보다 큰 경우는 없어야 한다.
=> 스택에는 나보다 작은 경우는 없어야 한다.

*/

#include <iostream>
#include <stack>
using namespace std;

typedef pair<int, long long> pi;
int n,p[500001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	
	long long ans = 0;
	stack<pi> st;
	
	// 한 명씩 확인
	for (int i = 0; i < n; i++) {	
		// i번째보다 작은 경우는 빼기.
		while (!st.empty() && st.top().first <p[i]) {
			ans++;	// 
			st.pop();
		}
		long long cnt = 0;
		// 최대 같은 경우가 몇 개 연속되어 있는 지 확인, 연속된 게 없다면 top에 있는 사람과만 쌍 이루기 가능.
		if(st.size())
			cnt = st.top().first == p[i] ? st.top().second+1 : 1;
		ans += cnt;
		
		st.push({ p[i],cnt });
	}
	cout << ans;
	return 0;
}