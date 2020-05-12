#include <iostream>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

int num;
bool isFriend[10][10];


int count(bool check[10]) {
	int free = -1;
	for (int i = 0; i < num; i++) {
		if (!check[i]) {
			free = i;
			break;
		}
	}
	
	if (free == -1) return 1;
	int ret = 0;
	for (int i = free+1; i < num; i++) {
		if (!check[i] && isFriend[free][i]) {
			check[i] = check[free] = true;
			ret += count(check);
			check[i] = check[free] = false;
		}
	}
	return ret;
}



int main() {
	int T;
	vector<int> ans;
	cin >> T;
	while (T--) {
		memset(isFriend, 0, sizeof(isFriend));
		
		int friends;
		cin >> num >> friends;
		cin.ignore();
		int x, y;
		for (int i = 0; i < friends; i++) {
			cin >> x >> y;
			isFriend[x][y] = isFriend[y][x] = true;
		}
		bool check[10];
		memset(check, 0, sizeof(check));
		ans.push_back(count(check));
	}
	for (int x : ans)
		cout << x << endl;

	return 0;
}
