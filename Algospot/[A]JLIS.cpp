// Algospot JLIS

#include <iostream>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int a[100], b[100];
int cache[101][101];
const long long INF = LLONG_MIN;

int jlis(int indexA, int indexB) {
	int& ret = cache[indexA+1][indexB+1];
	if (ret != -1) return ret;

	ret = 0;
	long long x = indexA == -1 ? INF : a[indexA];
	long long y = indexB == -1 ? INF : b[indexB];
	long long maxE = max(x, y);

	for (int i = indexA + 1; i < n; i++) {
		if (maxE < a[i]) 
			ret = max(ret, 1 + jlis(i, indexB));
	}
	for (int i = indexB + 1; i < m; i++) {
		if (maxE < b[i])
			ret = max(ret, 1 + jlis(indexA, i));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		memset(cache, -1, sizeof(cache));
		cin >> n >> m;
		for (int i = 0; i < n; i++) 
			cin >> a[i];
		for (int i = 0; i < m; i++)
			cin >> b[i];
		cout << jlis(-1, -1) << "\n";
	}

	

	return 0;
}