// 백준 1806번 부분합

// 생각보다 간단한 문제.
// start, end,sum을 두고 범위의 합이 s이상이면 최소값 확인
// start는 범위 시작, end는 범위 끝
// 만약 sum이 s보다 작으면 end을 +1해서 범위를 늘린다.
// 만약 s이상이면 최소값 확인하고 start를 하나 높인다.
// 

#include <iostream>

using namespace std;

int n, s;
int arr[100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	int sum = arr[0];
	int cnt = 1;
	int start = 0, end = 0;
	int answer = n + 1;

	while (end < n) {
		if (sum >= s) {
			answer = answer > cnt ? cnt : answer;
			sum -= arr[start];
			start += 1;
			cnt--;
		}
		else if (sum < s) {
			end++;
			sum += arr[end];
			cnt++;
		}		
	}
	if (answer == n + 1)
		answer = 0;
	cout << answer;

	return 0;
}