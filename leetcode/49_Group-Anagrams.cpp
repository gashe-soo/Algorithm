class Solution {
public:
    unordered_map<string, vector<string>> map;
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        for (string s : strs) {
            string newString = s;
            sort(newString.begin(), newString.end());

            map[newString].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto it = map.begin(); it != map.end(); it++) {
            ans.push_back(it->second);
        }
        return ans;
    }
};