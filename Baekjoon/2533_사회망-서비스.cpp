// 백준 2533번 사회망 서비스

#include <cstring>
#include <iostream>
#include <vector>

#define MAX 1000001
using namespace std;
int dp[MAX][2];
vector<int> node[MAX];
vector<int> tree[MAX];
int n;

void dfs(int now, int p)
{
    if (p != 0)
        tree[p].push_back(now);

    for (auto nxt : node[now]) {
        if (nxt == p)
            continue;
        dfs(nxt, now);
    }
}

int solve(int now, int flag)
{
    int& ret = dp[now][flag];
    if (ret != -1)
        return ret;
    ret = 0;

    if (!flag) {
        for (auto nxt : tree[now])
            ret += solve(nxt, 1);
    } else {
        for (auto nxt : tree[now]) {
            ret += min(solve(nxt, 1), solve(nxt, 0));
        }
        ret++;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    dfs(1, 0);

    memset(dp, -1, sizeof dp);
    cout << min(solve(1, 0), solve(1, 1));
}