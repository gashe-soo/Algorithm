class Solution {
public:
    bool check(char o, char c)
    {
        if (o == '(' && c == ')')
            return true;
        if (o == '{' && c == '}')
            return true;
        if (o == '[' && c == ']')
            return true;
        return false;
    }

    bool isValid(string s)
    {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{')
                st.push(c);
            else {
                if (st.empty())
                    return false;
                if (!check(st.top(), c))
                    return false;
                st.pop();
            }
        }
        if (!st.empty())
            return false;

        return true;
    }
};