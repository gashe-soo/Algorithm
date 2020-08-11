// 백준 9576번 책 나눠주기

/*
처음 풀이:
1. 범위를 저장 + 정렬
2. 각 숫자마다 언급된 횟수를 map으로 저장
3. 가장 적게 언급된 숫자를 찾아서 그 숫자를 가진 배열 중 크기가 작은 범위를 고르고 범위 배열에서 지운다.
4. 3번에서 삭제된 범위가 가진 숫자의 횟수를 하나씩 지운다.

최적화 풀이:
0. 아이디어는 기존 풀이와 거의 동일
1. 정렬시 숫자 오름차순 + 크기 오름차순
2. 범위를 확인하면서 선택되지 않았다면 선택하고 다음 범위 확인
3. 2번 반복
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> pi;
int n, m;
vector<pi> range;
bool visit[1001];

// 1.
bool cmp(pi a, pi b) {
	if (a.second == b.second)
		return a.first > b.first;
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc;
	int answer;
	cin >> tc;
	while (tc--) {
		memset(visit, 0, sizeof(visit));
		answer = 0;
		cin >> n >> m;
		range.clear();
		
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			range.push_back({ a,b });
		}
		
		sort(range.begin(), range.end(),cmp);
		
		for (int i = 0; i < m; i++) {
			// 2.
			for (int j = range[i].first; j <= range[i].second; j++) {
				if (!visit[j]) {
					visit[j] = true;
					break;
				}
			}
		}
		for (int i = 1; i <= n; i++)
			answer += visit[i];
		
		cout << answer << "\n";
	}

	return 0;
}

//=============처음 풀이======================
//#include <map>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstring>
//
//using namespace std;
//
//
//typedef pair<int, int> pi;
//int n, m;
//vector<pi> range;
//bool visit[1001];
//map<int, int> book;
//// 3. 가장 적게 언급된 숫자 찾기.
//int findMin() {
//	if (book.size() == 0) return -1;
//	int ret = 1001;
//	int num = -1;
//	for (auto it = book.begin(); it != book.end(); it++) {
//		if (it->second < ret) {
//			ret = it->second;
//			num = it->first;
//		}
//	}
//
//	return num;
//}
//
//// 3. 가장 크기가 작은 범위 찾기
//int find(int val) {
//	int idx = -1;
//	int cnt = 1001;
//	for (int i = 0; i < range.size(); i++) {
//		int start = range[i].first;
//		int end = range[i].second;
//
//		if (val < start || val>end) continue;
//
//		if (end - start < cnt) {
//			cnt = end - start;
//			idx = i;
//		}
//	}
//	return idx;
//}
//
//
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//
//	int tc;
//	int answer;
//	cin >> tc;
//	while (tc--) {
//		memset(visit, 0, sizeof(visit));
//		answer = 0;
//		cin >> n >> m;
//		book.clear();
//		range.clear();
//		book.clear();
//		for (int i = 0; i < m; i++) {
//			int a, b;
//			cin >> a >> b;
//			range.push_back({ a,b });
//		}
//
//		sort(range.begin(), range.end());
//		for (auto p : range) {
//			for (int i = p.first; i <= p.second; i++)
//				book[i]++;
//		}
//		int book_idx = findMin();
//		while (book_idx != -1) {
//
//			int range_idx = find(book_idx);
//			if (range_idx == -1) break;
//
//			int s = range[range_idx].first, e = range[range_idx].second;
//			// 4. 삭제할 범위에 존재하는 숫자의 횟수 줄이기.
//			visit[book_idx] = true;
//			for (int i = s; i <= e; i++) {
//				if (visit[i]) continue;
//				if (book[i]) book[i]--;
//				if (book[i] == 0) book.erase(i);
//			}
//
//			book.erase(book_idx);
//			range.erase(range.begin() + range_idx);
//
//
//			book_idx = findMin();
//			answer++;
//		}
//		cout << answer << "\n";
//	}
//
//	return 0;
//}