class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ans;
        unordered_map<int, int> m;
        for (int num : nums1) {
            m[num]++;
        }

        for (int num : nums2) {
            if (m[num]) {
                ans.push_back(num);
                m[num]--;
            }
        }
        return ans;
    }
};