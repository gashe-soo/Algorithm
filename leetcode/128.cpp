class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        if (nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());

        int ans = 0;
        int len = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                if (nums[i] == nums[i - 1] + 1) {
                    len++;
                } else {
                    ans = max(ans, len);
                    len = 1;
                }
            }
        }
        return max(ans, len);
    }
};