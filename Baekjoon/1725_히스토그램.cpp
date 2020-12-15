// 백준 1725번 히스토그램

#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

int n, arr[100002];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    arr[n] = 0;
    stack<int> st;

    st.push(-1);

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            int h = arr[st.top()];
            st.pop();
            int w = i - st.top() - 1;

            ans = max(ans, h * w);
        }
        st.push(i);
    }

    cout << ans;

    return 0;
}