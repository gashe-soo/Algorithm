// 백준 2014번 소수의 곱

/*
접근 : 
1) n번째 숫자가 나올 때까지 증가시키며 조건을 만족시키는 지 판단 => 시간초과
2) 우선순위 큐를 이용하여 n번째까지 pop.

풀이:
1. 우선순위 큐에 입력받은 소수를 push
2. pop하고 해당 값에 입력받은 소수를 곱하여 범위가 넘지 않는다면 push
3. 중복 제거를 위해 pop한 값이 소수로 나눠진다면 break.
*/

#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int prime[100];
int n, k;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> k >> n;
	
	for (int i = 0; i < k; i++) {
		cin >> prime[i];
	}
	priority_queue<int, vector<int>, greater<int>>pq;

	// 1.
	for (int i = 0; i < k; i++) {
		pq.push(prime[i]);
	}
	int val = 0;

	while (n--) {
		val = pq.top();
		pq.pop();
		
		for (int i = 0; i < k; i++) {
			long long x = (long long)val * prime[i];
			if (x >= INT_MAX) continue;	
			pq.push(val * prime[i]);	// 2.
			if (val % prime[i] == 0) break;	// 3
		}
	}

	cout << val;

	return 0;
}