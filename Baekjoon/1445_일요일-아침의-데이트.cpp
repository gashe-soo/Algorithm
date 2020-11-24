// 백준 1445번 일요일 아침의 데이트

/*
우선순위 큐 이용하여 해결
쓰레기 적은 칸, 쓰레기 인접이 적은 칸부터 go
만약 도착한다면 finish
*/

#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
typedef vector<int> pp;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int n, m;
char f[51][51];
bool v[51][51];
bool g[51][51];
pi start, arrive;

// 쓰레기 인접했는 지 파악
void get(int x, int y)
{
    g[x][y] = 0;
    if (f[x][y] == 'g')
        return;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if (f[nx][ny] == 'g')
        {
            g[x][y] = 1;
            return;
        }
    }
    return;
}

pi dji()
{
    priority_queue<pp, vector<pp>, greater<pp>> pq;

    int cur = 0;
    int side = 0;
    pq.push({cur, side, start.first, start.second});
    v[start.first][start.second] = 1;
    while (!pq.empty())
    {
        cur = pq.top()[0];
        side = pq.top()[1];
        int x = pq.top()[2], y = pq.top()[3];
        pq.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || v[nx][ny])
                continue;

            if (nx == arrive.first && ny == arrive.second)
                return {cur, side};
            // 다음 칸에 쓰레기 있는지 확인
            int p = f[nx][ny] == '.' ? 0 : 1;
            pq.push({cur + p, side + g[nx][ny], nx, ny});

            v[nx][ny] = 1;
        }
    }

    return {-1, -1};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> f[i][j];
            if (f[i][j] == 'S')
                start = {i, j};
            if (f[i][j] == 'F')
                arrive = {i, j};
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            get(i, j);
        }
    }

    pi ret = dji();
    cout << ret.first << " " << ret.second;

    return 0;
}