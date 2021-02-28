class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int j = 0;
        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++) {
            if (i > 0 && nums1[i] == nums1[i - 1])
                continue;

            while (j < nums2.size() && nums2[j] < nums1[i])
                j++;

            if (j == nums2.size())
                break;

            if (nums1[i] == nums2[j])
                ans.push_back(nums1[i]);
        }
        return ans;
    }
};