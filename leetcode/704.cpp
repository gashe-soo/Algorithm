class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int ans = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (target != nums[ans])
            return -1;
        return ans;
    }
};