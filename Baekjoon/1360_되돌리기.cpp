// 백준 1360번 되돌리기

/*
1번이고 난이도가 제일 낮았지만 제일 고생한 문제..
시간마다 결과물을 저장하고 되돌아가는 해결법.
map (실패) -> vector로 해결

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
string cmd;
char word;
int ud;
int time;
vector<pair<int, string>> ret;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	ret.push_back({ 0,"" });
	for (int i = 1; i <= n; i++) {
		cin >> cmd;
		if (cmd == "type") {
			cin >> word >> time;
			string tmp = ret[i - 1].second;
			ret.push_back({ time,tmp + word });
		}
		else {
			cin >> ud >> time;
			int c = time - ud;
			bool flag = false;
			for (int j = ret.size() - 1; j >= 0; j--) {
				if (ret[j].first < time - ud) {
					ret.push_back({ time,ret[j].second });
					flag = true;
					break;
				}
			}
			if (!flag) {
				ret.push_back({ time,"" });
			}
		}
	}
	string ans = ret[n].second;
	
	cout << ans;

	return 0;
}