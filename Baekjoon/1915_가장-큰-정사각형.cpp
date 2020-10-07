// 백준 1915번 가장 큰 정사각형

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int n, m, rect[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            rect[i][j] = s[j] - '0';
        }
    }

    int answer = rect[0][0];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (rect[i][j] != 1)
                continue;

            rect[i][j] = min({ rect[i - 1][j - 1], rect[i - 1][j], rect[i][j - 1] }) + 1;
            answer = answer > rect[i][j] ? answer : rect[i][j];
        }
    }

    cout << answer * answer;
    return 0;
}