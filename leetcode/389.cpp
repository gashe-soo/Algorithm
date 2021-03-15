class Solution {
public:
    char findTheDifference(string s, string t)
    {
        int alpha[26] = {
            0,
        };

        for (int i = 0; i < s.size(); i++) {
            alpha[s[i] - 'a']++;
        }

        for (int i = 0; i < t.size(); i++) {
            if (alpha[t[i] - 'a'] == 0)
                return t[i];
            else
                alpha[t[i] - 'a']--;
        }
        return 'a';
    }
};