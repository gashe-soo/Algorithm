class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr)
    {
        unordered_map<int, int> cnt;
        vector<int> ret;
        int size;

        for (int& a : arr)
            cnt[a]++;

        size = cnt.size();

        for (auto& it : cnt) {
            ret.push_back(it.second);
        }

        sort(ret.begin(), ret.end());
        ret.erase(unique(ret.begin(), ret.end()), ret.end());

        return ret.size() == size;
    }
};