// 백준 1197번 최소-스패닝-트리

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

struct Node {
    int cost, a, b;

    bool operator<(Node node)
    {
        return cost < node.cost;
    }
};

int v, e, a, b, c;

vector<Node> arr;
int p[10001];

ll ans;

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
    cin >> v >> e;
    for (int i = 1; i <= v; i++) {
        p[i] = i;
    }
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;

        arr.push_back({ c, a, b });
    }

    sort(arr.begin(), arr.end());

    int cnt = 0;
    for (int i = 0; i < e; i++) {
        if (cnt == v - 1)
            break;

        int x = find(arr[i].a);
        int y = find(arr[i].b);

        if (x > y) {
            swap(x, y);
        }
        if (x == y)
            continue;
        ans += arr[i].cost;
        p[y] = x;
        cnt++;
    }

    cout << ans;

    return 0;
}