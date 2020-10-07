// 백준 11404번 플로이드

#include <iostream>

using namespace std;

int n, m;
int city[101][101];

const int INF = 987654321;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            city[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        city[a][b] = min(city[a][b], c);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j)
                    continue;
                city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (city[i][j] < INF) {
                cout << city[i][j] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << "\n";
    }

    return 0;
}