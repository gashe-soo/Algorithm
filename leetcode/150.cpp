class Solution {
public:
    int cal(string ex, int a, int b)
    {
        if (ex == "+")
            return a + b;
        if (ex == "-")
            return a - b;
        if (ex == "*")
            return a * b;
        return a / b;
    }

    int evalRPN(vector<string>& tokens)
    {
        stack<int> st;
        int a, b;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(cal(tokens[i], b, a));
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};