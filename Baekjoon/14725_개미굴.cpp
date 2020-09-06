// 백준 14725번 개미굴

/*
이전에 풀이한 디스크 트리와 동일한 문제.
*/

#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n, k;
string ant[1000];
map<string, bool> m;

vector<string> split(string str) {
	string temp;
	vector<string> ret;

	for (int i = 1; i < str.size(); i++) {
		if (str[i] == ' ') {
			ret.push_back(temp);
			temp.clear();
		}
		else 
			temp += str[i];
	}
	ret.push_back(temp);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> k;
		getline(cin, ant[i]);
	}
	sort(ant, ant + n);

	for (int i = 0; i < n; i++) {
		vector<string> ret = split(ant[i]);
		string str;
		for (int i = 0; i < ret.size(); i++) {
			str +=ret[i]+"|";
			if (m[str]) {
				continue;
			}
			for (int j = 0; j < i; j++) 
				cout << "--";
			cout << ret[i] << "\n";
			m[str] = true;
		}
	}
	return 0;
}