// 백준 2458번 키-순서

#include <iostream>

using namespace std;

int n, m, a, b;
int arr[501][501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        arr[b][a] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][k] && arr[k][j])
                    arr[i][j] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
            cnt += arr[i][j] + arr[j][i];
        if (cnt == n - 1)
            ans++;
    }

    cout << ans;

    return 0;
}