// 백준 14427번 수열과 쿼리 15

/*
세그먼트 트리를 이용
1. 처음에 arr 받아서 초기화, 최소값과 idx 저장
2. 값이 변경되면 change 함수를 통해 해당 노드의 값을 변경
3. 값이 모두 변경되면 update를 통해 구간별 최소값,idx 변경
*/

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int n, m;
int arr[100001];

pi init(vector<pi>& tree, int node, int start, int end)
{
    if (start == end) {
        return tree[node] = { arr[start], start };
    }

    int mid = (start + end) / 2;

    pi a = init(tree, 2 * node + 1, start, mid);
    pi b = init(tree, 2 * node + 2, mid + 1, end);

    pi ret = a.first > b.first ? b : a;

    return tree[node] = ret;
}

pi update(vector<pi>& tree, int node, int start, int end, int idx)
{
    if (idx < start || end < idx) {
        return tree[node];
    }

    if (start == end)
        return tree[node];

    int mid = (start + end) / 2;

    pi a = update(tree, 2 * node + 1, start, mid, idx);
    pi b = update(tree, 2 * node + 2, mid + 1, end, idx);

    pi ret = a.first > b.first ? b : a;

    return tree[node] = ret;
}

void change(vector<pi>& tree, int node, int start, int end, int idx, int v)
{
    if (idx < start || end < idx)
        return;
    if (start == end && end == idx) {
        tree[node] = { v, idx };
        pi a = update(tree, 0, 0, n - 1, idx);
        return;
    }
    int mid = (start + end) / 2;

    change(tree, 2 * node + 1, start, mid, idx, v);
    change(tree, 2 * node + 2, mid + 1, end, idx, v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int h = (int)ceil(log2(n));
    int size = 1 << (h + 1);

    vector<pi> tree(size);
    init(tree, 0, 0, n - 1);

    cin >> m;
    for (int i = 0; i < m; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 2) {
            cout << tree[0].second + 1 << "\n";
        } else {
            int idx, v;
            cin >> idx >> v;
            change(tree, 0, 0, n - 1, idx - 1, v);
        }
    }

    return 0;
}