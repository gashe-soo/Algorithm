// 백준 10865번 친구 친구

#include <iostream>

using namespace std;

int n, m;
int f[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        f[a]++;
        f[b]++;
    }

    for (int i = 1; i <= n; i++) {
        cout << f[i] << "\n";
    }
    return 0;
}