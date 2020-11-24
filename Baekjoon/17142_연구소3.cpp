// 백준 17142번 연구소 3

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int n, m, answer;
int map[51][51];
vector<pi> virus;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void solve(vector<pi> arr)
{
    queue<pi> q;

    vector<vector<int>> dist(n, vector<int>(n, -1));

    for (pi p : arr) {
        q.push(p);
        dist[p.first][p.second] = 0;
    }

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || map[nx][ny] == 1 || dist[nx][ny] > -1)
                continue;
            q.push({ nx, ny });
            dist[nx][ny] = dist[x][y] + 1;
        }
    }
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == -1 && map[i][j] == 0)
                return;
            if (map[i][j])
                continue;
            ret = max(ret, dist[i][j]);
        }
    }

    answer = min(answer, ret);
    return;
}

void go(vector<pi> arr, int idx)
{
    if (arr.size() == m) {
        solve(arr);
        return;
    }
    for (int i = idx; i < virus.size(); i++) {
        arr.push_back(virus[i]);
        go(arr, i + 1);
        arr.pop_back();
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                virus.push_back({ i, j });
            }
        }
    }
    answer = 987654321;

    go({}, 0);
    if (answer == 987654321)
        cout << -1;
    else
        cout << answer;
    return 0;
}