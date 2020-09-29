// 백준 2667번 단지번호붙이기

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int n;
int map[26][26];
vector<int> ans;
bool v[26][26];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs(int i, int j)
{
    if (v[i][j])
        return;
    queue<pi> q;
    int sum = 0;
    q.push({ i, j });
    v[i][j] = 1;

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        sum++;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || map[nx][ny] == 0 || v[nx][ny]) {
                continue;
            }
            q.push({ nx, ny });
            v[nx][ny] = 1;
        }
    }
    ans.push_back(sum);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    string t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        for (int j = 0; j < n; j++) {
            map[i][j] = t[j] - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1) {
                bfs(i, j);
            }
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int s : ans) {
        cout << s << "\n";
    }

    return 0;
}