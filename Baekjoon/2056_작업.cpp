// 백준 2056번 작업

// 풀이 1. 위상정렬
// 풀이 2. dp

#include <algorithm>
#include <iostream>

using namespace std;

int n;
int dp[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    int a, b;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        int val = 0;
        int c;
        for (int j = 0; j < b; j++) {
            cin >> c;
            val = max(val, dp[c]); // 현재 연결된 애들 중 가장 큰 거
        }
        dp[i] = val + a; // 가장 큰 거에 비용 더하기
        ans = max(ans, dp[i]);
    }

    cout << ans;
}

// #include <algorithm>
// #include <iostream>
// #include <queue>

// using namespace std;
// typedef pair<int, int> pi;

// int n;
// vector<int> adj[10001];
// int cost[10001];
// int p[10001];
// int total[10001];

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n;
//     int a, b;
//     for (int i = 1; i <= n; i++) {
//         cin >> cost[i] >> a;
//         for (int j = 0; j < a; j++) {
//             cin >> b;
//             adj[b].push_back(i);
//             p[i]++;
//         }
//     }

//     queue<pi> q;

//     for (int i = 1; i <= n; i++) {
//         total[i] = cost[i];
//         if (p[i] == 0) {
//             q.push({ total[i], i });
//         }
//     }
//     int ans = 0;
//     while (!q.empty()) {
//         int c = q.front().first;
//         int from = q.front().second;
//         q.pop();

//         for (int to : adj[from]) {
//             total[to] = max(total[to], c + cost[to]);
//             p[to]--;
//             if (p[to] == 0) {
//                 q.push({ total[to], to });
//             }
//         }
//     }
//     for (int i = 1; i <= n; i++) {
//         ans = max(ans, total[i]);
//     }
//     cout << ans;
//     return 0;
// }