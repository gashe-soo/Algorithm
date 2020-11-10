// 백준 15926번 현욱은 괄호왕이야

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int n;
string str;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> str;

    stack<int> st;
    int ans = 0;
    st.push(-1);
    for (int i = 0; i < n; i++) {
        if (str[i] == '(')
            st.push(i);
        else {
            st.pop();
            if (!st.empty()) {
                ans = max(ans, i - st.top());
            } else {
                st.push(i);
            }
        }
    }
    cout << ans;

    return 0;
}