#include <iostream>
#include <string>
#include <map>

// 백준 4195번 친구 네트워크

using namespace std;

// union find로 접근 
// 대표적인 union find 문제이므로 union / find 함수 만듦.
// 다만 개수를 도출해야 하므로 개수를 세도록 다른 배열 선언.
// 다만 입출력에서 시간이 오래 걸려 정답 찾아봤지만 허무한 "\n";;

int num[200001];
int p[200001];

int findP(int i) {
	if (i == p[i]) return i;
	return p[i] = findP(p[i]);
}

int Union(int a, int b) {
	int x = findP(a);
	int y = findP(b);
	if (x != y) {
		p[y] = x;
		num[x] += num[y];
	}
	return num[x];
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		map<string, int> m;
		int n;
		cin >> n;
		int idx = 0;
		for (int i = 1; i < 2*n+1; i++) {
			p[i] = i;
			num[i] = 1;
		}
		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;
			
			if (m.find(a) == m.end())  {
				m[a] = ++idx;
			}
			 if (m.find(b) == m.end()) {
				m[b] = ++idx;
			}

			 cout << Union(m[a], m[b]) << "\n";
		}
	}


	return 0;
}