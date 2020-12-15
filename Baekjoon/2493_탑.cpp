// 백준 2493번 탑

#include <iostream>
#include <stack>

using namespace std;

int n, arr[500001], idx[500001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            idx[st.top()] = i + 1;
            st.pop();
        }
        st.push(i);
    }
    for (int i = 0; i < n; i++)
        cout << idx[i] << " ";

    return 0;
}