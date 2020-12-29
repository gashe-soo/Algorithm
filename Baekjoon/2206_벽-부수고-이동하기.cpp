// 백준 2206번 벽-부수고-이동하기

#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Node {
    int x, y, c, d;
};

int n, m;
int wall[1001][1001];
bool v[1001][1001][2];
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
string in;

int bfs()
{
    queue<Node> q;
    q.push({ 0, 0, 1, 1 });
    v[0][0][1] = 1;

    while (!q.empty()) {
        Node node = q.front();
        q.pop();
        if (node.x == n - 1 && node.y == m - 1) {
            return node.d;
        }

        for (int i = 0; i < 4; i++) {
            int nx = node.x + dx[i], ny = node.y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (wall[nx][ny] == 0 && !v[nx][ny][node.c]) {
                v[nx][ny][node.c] = 1;
                q.push({ nx, ny, node.c, node.d + 1 });
            }

            if (wall[nx][ny] == 1 && node.c == 1) {
                v[nx][ny][1] = 1;
                q.push({ nx, ny, 0, node.d + 1 });
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> in;
        for (int j = 0; j < m; j++)
            wall[i][j] = in[j] - '0';
    }

    cout << bfs();
    return 0;
}