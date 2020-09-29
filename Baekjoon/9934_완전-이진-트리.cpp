// 백준 9934번 완전 이진 트리

// 분할 정복

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int k;

vector<int> ans[11];

void split(vector<int> arr, int depth)
{
    if (depth == k)
        return;
    int size = arr.size();
    ans[depth].push_back(arr[size / 2]);

    vector<int> left, right;
    for (int i = 0; i < size / 2; i++) {
        left.push_back(arr[i]);
    }
    for (int i = size / 2 + 1; i < size; i++) {
        right.push_back(arr[i]);
    }

    split(left, depth + 1);
    split(right, depth + 1);

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> k;

    int size = pow(2, k) - 1;
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    split(arr, 0);

    for (int i = 0; i < k; i++) {
        for (int x : ans[i]) {
            cout << x << ' ';
        }
        cout << "\n";
    }

    return 0;
}