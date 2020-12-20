// 백준 11660번 구간-합-구하기-5

#include <iostream>

using namespace std;

int n, m, num, a, b, c, d, sum[1025][1025];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> num;
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + num;
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c >> d;
        cout << sum[c][d] - sum[a - 1][d] - sum[c][b - 1] + sum[a - 1][b - 1] << "\n";
    }

    return 0;
}