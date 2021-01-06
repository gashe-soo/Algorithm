// 백준 1693번 트리-색칠하기

// tree-dp

#include <cstring>
#include <iostream>
#include <vector>

#define MAX 100001
using namespace std;
typedef long long ll;

int n;
ll dp[MAX][20];
vector<int> input[MAX];
vector<int> tree[MAX];

void make(int p, int c)
{
    for (int child : input[c]) {
        if (child == p)
            continue;
        tree[c].push_back(child);
        make(c, child);
    }
}

ll solve(int num, int color)
{
    ll& ret = dp[num][color];
    if (ret != -1)
        return ret;

    ret = color;
    for (int child : tree[num]) {
        ll val = 1e16;
        for (int i = 1; i < 20; i++) {
            if (color == i)
                continue;
            val = min(val, solve(child, i));
        }
        ret += val;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    memset(dp, -1, sizeof(dp));
    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        input[a].push_back(b);
        input[b].push_back(a);
    }

    make(0, 1);
    ll ans = 1e16;
    for (int i = 1; i < 20; i++) {
        ans = min(ans, solve(1, i));
    }

    cout << ans;

    return 0;
}