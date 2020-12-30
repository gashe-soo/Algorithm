// 백준 14267번 내리-칭찬

#include <iostream>
#include <queue>
#include <vector>

#define MAX 1000001

using namespace std;

int n, m, arr[MAX], a, b;
vector<int> child[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a == -1)
            continue;
        child[a].push_back(i);
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        arr[a] += b;
    }

    queue<int> q;

    q.push(1);

    while (!q.empty()) {
        int p = q.front();
        q.pop();

        for (int c : child[p]) {
            arr[c] += arr[p];
            q.push(c);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}