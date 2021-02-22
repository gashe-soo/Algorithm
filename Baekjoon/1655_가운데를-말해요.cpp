// 백준 1655번 가운데를-말해요

#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> minHeap;
priority_queue<int> maxHeap;

int getMid(int num)
{
    if (minHeap.size() == maxHeap.size())
        maxHeap.push(num);
    else
        minHeap.push(num);

    if (!minHeap.empty() && !maxHeap.empty() && (maxHeap.top() > minHeap.top())) {
        int a = maxHeap.top();
        int b = minHeap.top();
        maxHeap.pop();
        minHeap.pop();

        maxHeap.push(b);
        minHeap.push(a);
    }

    return maxHeap.top();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        cout << getMid(num) << "\n";
    }

    return 0;
}