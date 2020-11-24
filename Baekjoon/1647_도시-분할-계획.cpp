// 백준 1647번 도시 분할 계획

/*
MST 만든 후 최대값 삭제
크루스칼 알고리즘 사용
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct Node {
    int c, a, b;
} node;

int n, m;
vector<node> adj;

int p[100001];

bool cmp(node x, node y)
{
    return x.c < y.c;
}
int find(int idx)
{
    if (p[idx] == idx)
        return idx;
    return p[idx] = find(p[idx]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        adj.push_back({ z, x, y });
    }

    sort(adj.begin(), adj.end(), cmp);

    int sum = 0;
    int cnt = 0;

    for (node arr : adj) {
        int c = arr.c, x = arr.a, y = arr.b;

        int i = find(x), j = find(y);
        if (i == j)
            continue;
        p[j] = i;
        sum += c;
        if (++cnt == n - 2)
            break;
    }
    cout << sum;

    return 0;
}