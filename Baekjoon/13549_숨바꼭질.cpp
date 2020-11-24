// 백준 13549번 숨바꼭질

#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

int n, k;
const int INF = 987654321;

int get()
{
    queue<pi> q;
    q.push({ 0, n });
    vector<int> dist(100001, INF);
    dist[n] = 0;
    while (!q.empty()) {
        int time = q.front().first;
        int from = q.front().second;
        q.pop();
        if (from < 0 || from > 100000 || dist[from] < time)
            continue;

        if (from == k)
            return time;
        if (from > 0 && dist[from - 1] > time + 1) {
            q.push({ time + 1, from - 1 });
            dist[from - 1] = time + 1;
        }
        if (from < 100000 && dist[from + 1] > time + 1) {
            q.push({ time + 1, from + 1 });
            dist[from + 1] = time + 1;
        }
        if (from <= 50000 && dist[from * 2] > time) {
            q.push({ time, from * 2 });
            dist[from * 2] = time;
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    cout << get();
    return 0;
}