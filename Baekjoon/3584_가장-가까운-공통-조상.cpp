// 백준 3584번 가장-가까운-공통-조상

#include <cstring>
#include <iostream>

using namespace std;

int n, a, b, p[10001];
bool v[10001];

int lca(int x, int y)
{
    while (x) {
        v[x] = 1;
        x = p[x];
    }
    while (y) {
        if (v[y])
            return y;
        y = p[y];
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        memset(p, 0, sizeof(p));
        memset(v, 0, sizeof(v));

        for (int i = 0; i < n - 1; i++) {
            cin >> a >> b;
            p[b] = a;
        }

        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
    return 0;
}

// // 백준 3584번 가장-가까운-공통-조상

// #include <cstring>
// #include <iostream>
// #include <vector>

// using namespace std;

// int n, p[10001][16], a, b, depth[10001];
// vector<int> child[10001];

// void go(int idx, int d)
// {
//     depth[idx] = d;
//     for (int c : child[idx]) {
//         go(c, d + 1);
//     }
// }
// int lca(int x, int y)
// {
//     if (depth[x] > depth[y]) {
//         swap(x, y);
//     }

//     for (int i = 15; i >= 0; i--) {
//         if ((1 << i) <= depth[y] - depth[x])
//             y = p[y][i];
//     }
//     if (x == y)
//         return x;

//     for (int i = 15; i >= 0; i--) {
//         if (p[x][i] != p[y][i]) {
//             x = p[x][i];
//             y = p[y][i];
//         }
//     }
//     return p[x][0];
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int tc;
//     cin >> tc;
//     while (tc--) {
//         memset(depth, 0, sizeof(depth));
//         memset(p, 0, sizeof(p));
//         for (int i = 0; i <= 10001; i++)
//             child[i].clear();
//         cin >> n;
//         for (int i = 0; i < n - 1; i++) {
//             cin >> a >> b;
//             child[a].push_back(b);
//             p[b][0] = a;
//         }
//         int leaf;
//         for (int i = 1; i <= n; i++) {
//             if (child[i].size() == 0) {
//                 leaf = i;
//                 break;
//             }
//         }

//         while (p[leaf][0] != 0) {
//             leaf = p[leaf][0];
//         }

//         go(leaf, 1);

//         for (int j = 1; j < 16; j++) {
//             for (int i = 1; i <= n; i++) {
//                 p[i][j] = p[p[i][j - 1]][j - 1];
//             }
//         }

//         cin >> a >> b;
//         cout << lca(a, b) << "\n";
//     }

//     return 0;
// }