// 백준 2842번 집배원 한상덕

/*
실패 -> 풀이 참고

투포인터 + bfs로 해결

*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

char map[51][51];
int h[51][51];
int n, house;
bool v[51][51];
vector<int> fatigue;
pi office;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'P')
                office = { i, j };
            if (map[i][j] == 'K')
                house++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> h[i][j];
            fatigue.push_back(h[i][j]);
        }
    }

    sort(fatigue.begin(), fatigue.end());
    fatigue.erase(unique(fatigue.begin(), fatigue.end()), fatigue.end());

    int low = 0, high = 0;
    int ans = 987654321;
    while (low < fatigue.size()) {
        queue<pi> q;
        memset(v, false, sizeof(v));
        int k = 0;

        int p = h[office.first][office.second];
        if (p >= fatigue[low] && p <= fatigue[high]) {
            q.push(office);
            v[office.first][office.second] = true;
        }

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || v[nx][ny]) {
                    continue;
                }

                if (h[nx][ny] >= fatigue[low] && h[nx][ny] <= fatigue[high]) {
                    q.push({ nx, ny });
                    v[nx][ny] = true;

                    if (map[nx][ny] == 'K')
                        k++;
                }
            }
        }
        if (k == house) {
            ans = min(ans, fatigue[high] - fatigue[low]);
            low++;
        } else if (high + 1 < fatigue.size()) {
            high++;
        } else {
            break;
        }
    }
    cout << ans;

    return 0;
}
