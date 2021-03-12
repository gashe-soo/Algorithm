// 프로그래머스 level2 게임 맵 최단거리

#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> pi;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int n, m, arr[101][101];

int bfs(vector<vector<int>>& maps)
{
    queue<pi> q;

    q.push({ 0, 0 });
    arr[0][0] = 1;

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] || !maps[nx][ny])
                continue;
            q.push({ nx, ny });
            arr[nx][ny] = arr[x][y] + 1;
        }
    }

    int ret = arr[n - 1][m - 1];

    return ret == 0 ? -1 : ret;
}

int solution(vector<vector<int>> maps)
{
    n = maps.size();
    m = maps[0].size();
    return bfs(maps);
}