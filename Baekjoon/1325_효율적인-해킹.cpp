// 백준 1325번 효율적인 해킹

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<int> com[10001];
vector<int> ans;
bool v[10001];

int solve(int p)
{
    queue<int> q;
    q.push(p);
    memset(v, 0, sizeof(v));
    v[p] = 1;
    int ret = 1;
    while (!q.empty()) {
        int from = q.front();
        q.pop();

        for (int to : com[from]) {
            if (v[to])
                continue;
            q.push(to);
            v[to] = 1;
            ret++;
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        com[b].push_back(a);
    }

    int maxVal = 0;

    for (int i = 1; i <= n; i++) {
        int v = solve(i);
        if (v > maxVal) {
            maxVal = v;
            ans.clear();
            ans.push_back(i);
        } else if (v == maxVal) {
            ans.push_back(i);
        }
    }

    for (int i : ans) {
        cout << i << " ";
    }

    return 0;
}