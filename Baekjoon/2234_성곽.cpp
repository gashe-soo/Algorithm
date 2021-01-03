// 백준 2234번 성곽

/*
1. bfs로 방의 번호, 방의 개수 확인
2. 한 번 더 bfs로 방마다 돌면서 벽 너머가 다른 방이면 최대 넓이 확인
*/

#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pi;

int n, m, arr[51][51], room[51][51], area[2501], sum[2501];
int roomNum;
bool v[51][51];
int dx[4] = { 0, -1, 0, 1 }, dy[4] = { -1, 0, 1, 0 };

// 서북동남

void bfs1(int a, int b)
{
    if (room[a][b])
        return;
    roomNum++;

    queue<pi> q;

    q.push({ a, b });
    room[a][b] = roomNum;

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        area[roomNum]++;
        for (int i = 0; i < 4; i++) {
            if ((arr[x][y] & (1 << i)) == (1 << i)) // 벽인 경우 생략
                continue;
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || room[nx][ny])
                continue;

            q.push({ nx, ny });
            room[nx][ny] = roomNum;
        }
    }
    return;
}

// 최대 넓이 확인
void bfs2(int a, int b)
{
    if (v[a][b])
        return;
    int num = room[a][b];

    queue<pi> q;
    q.push({ a, b });
    v[a][b] = 1;

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || v[nx][ny])
                continue;
            // 만약 벽이 있고 다른 영역이면 최대 값 확인 후 continue
            if (((arr[x][y] & (1 << i)) == (1 << i)) && room[nx][ny] != num) {
                sum[num] = max(sum[num], area[num] + area[room[nx][ny]]);
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

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bfs1(i, j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bfs2(i, j);
        }
    }

    cout << roomNum << endl;
    cout << *max_element(area + 1, area + 1 + roomNum) << endl;
    cout << *max_element(sum + 1, sum + 1 + roomNum) << endl;
    return 0;
}