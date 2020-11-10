// 백준 10828번 스택

#include <iostream>
#include <stack>

using namespace std;

stack<int> st;

void solve(string cmd)
{
    if (cmd == "top") {
        if (!st.empty()) {
            cout << st.top() << "\n";
        } else {
            cout << "-1\n";
        }
    } else if (cmd == "size") {
        cout << st.size() << "\n";
    } else if (cmd == "pop") {
        if (st.empty()) {
            cout << "-1\n";
        } else {
            cout << st.top() << "\n";
            st.pop();
        }
    } else if (cmd == "empty") {
        cout << st.empty() << "\n";
    } else {
        st.push(stoi(cmd.substr(5)));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    cin.ignore();
    string cmd;
    for (int i = 0; i < n; i++) {
        getline(cin, cmd);
        solve(cmd);
    }

    return 0;
}