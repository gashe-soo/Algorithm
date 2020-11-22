// 백준 1005번 ACM Craft

// 위상정렬
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k, d, x, y, w;
int time[1001];
int p[1001];
int ans[1001];
vector<int> adj[1001];

void solve()
{
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (p[i] == 0) {
            q.push(i);
            ans[i] = time[i];
        }
    }
    while (!q.empty()) {
        int from = q.front();
        q.pop();

        for (int to : adj[from]) {
            ans[to] = max(ans[to], ans[from] + time[to]);
            p[to]--;
            if (p[to] == 0)
                q.push(to);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {

        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            p[i] = 0;
            ans[i] = 0;
            adj[i].clear();
            cin >> time[i];
        }
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            adj[x].push_back(y);
            p[y]++;
        }
        cin >> w;
        solve();
        cout << ans[w] << "\n";
    }
    return 0;
}