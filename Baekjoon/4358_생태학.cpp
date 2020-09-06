// 백준 4358번 생태학

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string name;
	map<string, int> tree;
	int sum = 0;
	getline(cin, name);
	while (!name.empty()) {
		tree[name]++;
		sum++;
		getline(cin, name);
	}

	for (auto it = tree.begin(); it != tree.end(); it++) {
		double ratio = (double)it->second / (double)sum;
		cout << fixed;
		cout.precision(4);
		cout << it->first << " " << 100 * ratio << endl;
	}


	return 0;
}