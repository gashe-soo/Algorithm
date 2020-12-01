class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> freq;
        for (int num : nums)
            ++freq[num];

        int n = nums.size();
        vector<vector<int>> buckets(n + 1);

        for (auto& f : freq)
            buckets[f.second].push_back(f.first);

        vector<int> result;

        int count = 0;
        for (int i = n; i >= 0; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                count++;
            }
            if (count == k)
                return result;
        }
        return result;
    }
};