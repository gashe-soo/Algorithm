// 백준 1766번 문제집

// 위상정렬 + 우선순위큐

/* 
조건 2번을 보고 바로 위상정렬 떠올림. 
+
조건 3번 때문에 우선순위 큐 이용

예상 시간복잡도 O(nlogn)
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int p[32001];
vector<int> adj[32001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        p[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) {
        if (p[i] == 0)
            pq.push(i);
    }

    while (!pq.empty()) {
        int from = pq.top();
        pq.pop();
        cout << from << " ";
        for (int to : adj[from]) {
            p[to]--;
            if (p[to] == 0) {
                pq.push(to);
            }
        }
    }

    return 0;
}