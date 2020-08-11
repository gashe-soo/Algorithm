// 백준 2887번 행성 터널

/*
x,y,z에 대해 각각 정렬 후에 가까운 거리 업데이트
map [(a,b)] a번-b번 사이의 거리를 저장.
저장한 결과를 정렬하여 크루스칼 알고리즘 적용
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

struct Planet {
	int x, y, z, num;
};

typedef pair<int, int> pi;
typedef pair<int, pi> pp;


int n;
int p[100001];
Planet arr[100001];
vector<pp> ans;
map<pi, int> m;
int answer;

int find(int idx) {
	if (idx == p[idx]) return idx;
	return p[idx] = find(p[idx]);
}

void insert() {
	for (int i = 0; i < n - 1; i++) {
		Planet front = arr[i];
		Planet rear = arr[i + 1];
		pi node;
		if (front.num > rear.num)
			node = { rear.num, front.num };
		else
			node = { front.num, rear.num };

		if (m.find(node) == m.end()) {
			m[node] = min({ abs(front.x - rear.x), abs(front.y - rear.y), abs(front.z - rear.z) });
		}
	}
}

bool cx(Planet a, Planet b) {
	return a.x < b.x;
}
bool cy(Planet a, Planet b) {
	return a.y < b.y;
}
bool cz(Planet a, Planet b) {
	return a.z < b.z;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		p[i] = i;
		int x, y, z;
		cin >> x >> y >> z;
		Planet node = { x,y,z,i + 1 };
		arr[i] = node;
	}

	sort(arr, arr+n, cx);
	insert();
	sort(arr, arr+n, cy);
	insert();
	sort(arr, arr+n, cz);
	insert();

	for (auto it = m.begin(); it != m.end(); it++) {
		ans.push_back({ it->second, it->first });
	}

	sort(ans.begin(), ans.end());
	int cnt = 0;
	for (int i = 0; i < ans.size(); i++) {

		int cost = ans[i].first;
		int x = ans[i].second.first, y = ans[i].second.second;

		int a = find(x), b = find(y);
		if (a != b) {
			p[b] = a;
			answer += cost;
			cnt++;
		}
		if (cnt == n - 1) break;
	}
	cout << answer;
	return 0;
}