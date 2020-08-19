// 백준 7432번 디스크 트리
/*
map 이용
처음에는 \을 기준으로 depth을 나누어 depth에 따라 출력했더니 출력 초과
-> 풀이 참고하여 해결.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
using namespace std;

int n;
string path[501];
map<string, bool> m;

vector<string> split(string str) {
	vector<string> ret;
	string temp;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '\\') {
			ret.push_back(temp);
			temp.clear();
		}
		else {
			temp += str[i];
		}
	}
	ret.push_back(temp);
	return ret;
}



void insert(string s) {
	vector<string> p = split(s);
	string str =" ";
	for (int i = 0; i < p.size(); i++) {
		str += p[i];
		if (!m[str]) {
			m[str] = true;
			for (int j = 0; j < i; j++) {
				cout << " ";
			}
			cout << p[i] << "\n";
		}
		str += "\\";
	}

	return;
}

bool cmp(string a, string b) {
	vector<string> x = split(a);
	vector<string> y = split(b);

	return x < y;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> path[i];
	}
	sort(path, path + n,cmp);
	
	for(int i=0;i<n;i++){
		insert(path[i]);
	}
}