// 백준 5549번 행성 탐사

#include <iostream>
#include <string>
#include <vector>

using namespace std;

char map[1001][1001];
int dp[1001][1001][3];
int n, m, k;

int get(char c)
{
    if (c == 'J')
        return 0;
    if (c == 'O')
        return 1;
    return 2;
}

void make()
{
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < 3; k++) {
                dp[i][j][k] = dp[i - 1][j][k] + dp[i][j - 1][k] - dp[i - 1][j - 1][k];
                if (get(map[i][j]) == k) {
                    dp[i][j][k]++;
                }
            }
        }
    }
}

void print(int a, int b, int c, int d)
{
    vector<int> ans;
    for (int i = 0; i < 3; i++) {
        int ret;
        ret = dp[c][d][i] - (dp[a - 1][d][i] + dp[c][b - 1][i]) + dp[a - 1][b - 1][i];
        ans.push_back(ret);
    }
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n >> k;
    string s;
    for (int i = 1; i <= m; i++) {
        cin >> s;
        for (int j = 1; j <= n; j++) {
            map[i][j] = s[j - 1];
        }
    }

    make();

    for (int i = 0; i < k; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        print(a, b, c, d);
    }

    return 0;
}