class Solution {
public:
    string mergeAlternately(string word1, string word2)
    {
        int len = min(word1.size(), word2.size());
        string ret;
        for (int i = 0; i < len; i++) {
            ret += word1[i];
            ret += word2[i];
        }

        if (word1.size() >= word2.size()) {
            ret += word1.substr(len);
        } else {
            ret += word2.substr(len);
        }

        return ret;
    }
};