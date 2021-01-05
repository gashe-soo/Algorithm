// 백준 2696번 중앙값-구하기

#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc, m;
    cin >> tc;
    while (tc--) {
        cin >> m;

        priority_queue<int, vector<int>, greater<int>> minpq;
        priority_queue<int> maxpq;
        int input;
        int cnt = 0;
        cout << m / 2 + 1 << "\n";
        for (int i = 1; i <= m; i++) {
            cin >> input;

            if (maxpq.size() == minpq.size()) {
                maxpq.push(input);
            } else {
                minpq.push(input);
            }

            if (!maxpq.empty() && !minpq.empty() && (maxpq.top() > minpq.top())) {
                int a = maxpq.top();
                maxpq.pop();
                int b = minpq.top();
                minpq.pop();

                minpq.push(a);
                maxpq.push(b);
            }

            if (i % 2) {
                cout << maxpq.top() << " ";
            }
            if (i % 20 == 0) {
                cout << "\n";
            }
        }

        cout << "\n";
    }
    return 0;
}