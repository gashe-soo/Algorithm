// 백준 11659번 구간-합-구하기-4

#include <iostream>

using namespace std;

int n, m, arr[100001], sum[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    sum[0] = arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum[i] += sum[i - 1] + arr[i];
    }

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << sum[b] - sum[a - 1] << "\n";
    }

    return 0;
}