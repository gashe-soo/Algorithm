// 백준 4963번 섬의 개수

// bfs

#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pi;

int w, h, cnt;
int map[50][50];
bool v[50][50];
int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

void bfs(int x, int y)
{
    if (v[x][y] || map[x][y] == 0)
        return;
    cnt++;
    queue<pi> q;

    v[x][y] = true;
    q.push({ x, y });

    while (!q.empty()) {
        pi from = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = from.first + dx[i], ny = from.second + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w || v[nx][ny] || map[nx][ny] == 0)
                continue;
            q.push({ nx, ny });
            v[nx][ny] = true;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (true) {
        cin >> w >> h;
        if ((w || h) == 0)
            break;
        cnt = 0;
        memset(v, 0, sizeof(v));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                bfs(i, j);
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}