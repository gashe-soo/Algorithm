// 백준 11725번 트리의 부모 찾기

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
int p[100001];
bool v[100001];
vector<int> adj[100001];

void solve()
{
    queue<int> q;

    q.push(1);
    v[1] = 1;

    while (!q.empty()) {
        int parent = q.front();
        q.pop();

        for (int child : adj[parent]) {
            if (v[child])
                continue;
            p[child] = parent;
            v[child] = 1;
            q.push(child);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int a, b;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    solve();

    for (int i = 2; i <= n; i++) {
        cout << p[i] << "\n";
    }

    return 0;
}