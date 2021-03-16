class Solution {
public:
    int maxNumberOfBalloons(string text)
    {
        vector<int> m(26, 0);

        for (auto c : text)
            m[c - 'a']++;

        int ans = 1e4 + 1;
        string obj = "balon";

        for (char c : obj) {
            int idx = c - 'a';

            if (c == 'o' || c == 'l') {
                ans = min(ans, m[idx] / 2);
            } else {
                ans = min(ans, m[idx]);
            }
        }
        return ans;
    }
};