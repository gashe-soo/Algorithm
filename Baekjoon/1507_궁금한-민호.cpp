// 백준 1507번 궁금한 민호

/*
플로이드 와샬

*/

#include <iostream>

using namespace std;

int n;
int city[20][20];
bool v[20][20];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> city[i][j];
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j || j == k || k == i) continue;
				if (city[i][j] == city[i][k] + city[k][j]) {
					v[i][j] = true;
				}
				else if (city[i][j] > city[i][k] + city[k][j]) {
					cout << "-1";
					return 0;
				}
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (!v[i][j]) {
				answer += city[i][j];
			}
		}
	}
	cout << answer;

	return 0;
}