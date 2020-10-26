#include <bits/stdc++.h>

using namespace std;

char getReverse(char c)
{
    if (c == ']')
        return '[';
    if (c == '}')
        return '{';
    return '(';
}

// Complete the isBalanced function below.
string isBalanced(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        if (c == '[' || c == '{' || c == '(') {
            st.push(c);
        } else {
            if (st.empty())
                return "NO";
            if (getReverse(c) == st.top()) {
                st.pop();
            } else {
                return "NO";
            }
        }
    }
    if (!st.empty())
        return "NO";
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
