// 백준 20166번 문자열 지옥에 빠진 호석

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef pair<int, int> pi;
typedef pair<string, pi> ps;

int n, m, k;
char map[11][11];
unordered_map<string, int> t;
int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

pi next(pi p)
{
    int x = p.first, y = p.second;
    if (x == n) {
        x = 0;
    } else if (x == -1) {
        x = n - 1;
    }

    if (y == m) {
        y = 0;
    } else if (y == -1) {
        y = m - 1;
    }
    return { x, y };
}

void bfs(int x, int y)
{
    queue<ps> q;
    string s = string(1, map[x][y]);
    q.push({ s, { x, y } });
    t[s]++;

    while (!q.empty()) {
        string str = q.front().first;
        pi p = q.front().second;
        q.pop();

        if (str.size() == 5)
            continue;

        for (int i = 0; i < 8; i++) {

            pi np = next({ p.first + dx[i], p.second + dy[i] });
            string ns = str + map[np.first][np.second];
            t[ns]++;
            q.push({ ns, np });
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;

    string s;

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            map[i][j] = s[j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bfs(i, j);
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> s;
        cout << t[s] << "\n";
    }

    return 0;
}