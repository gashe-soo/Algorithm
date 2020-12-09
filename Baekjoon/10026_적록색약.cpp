// 백준 10026번 적록색약

#include <iostream>
#include <queue>
#include <string>

using namespace std;
typedef pair<int, int> pi;
int n;
char map[101][101];
bool v[101][101];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
queue<pi> q;
int cnt;

void init()
{
    cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            v[i][j] = 0;
}

void no(int x, int y)
{
    if (v[x][y])
        return;
    cnt++;
    q.push({ x, y });
    v[x][y] = 1;

    while (!q.empty()) {
        pi now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.first + dx[i], ny = now.second + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || v[nx][ny] || map[nx][ny] != map[x][y])
                continue;
            q.push({ nx, ny });
            v[nx][ny] = 1;
        }
    }
}

void yes(int x, int y)
{
    if (v[x][y])
        return;
    cnt++;
    q.push({ x, y });
    v[x][y] = 1;

    while (!q.empty()) {
        pi now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.first + dx[i], ny = now.second + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || v[nx][ny])
                continue;
            if (map[x][y] == 'B') {
                if (map[nx][ny] != 'B')
                    continue;
            } else {
                if (map[nx][ny] == 'B')
                    continue;
            }
            q.push({ nx, ny });
            v[nx][ny] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < n; j++)
            map[i][j] = str[j];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            no(i, j);
        }
    }
    cout << cnt << " ";
    init();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            yes(i, j);
        }
    }
    cout << cnt;
    return 0;
}