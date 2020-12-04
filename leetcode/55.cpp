class Solution {
public:
    bool canJump(vector<int>& nums)
    {

        if (nums.size() <= 1)
            return true;
        if (nums[0] == 0)
            return false;
        vector<bool> dp(nums.size(), false);
        dp[0] = true;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] && ((nums[j] + j) >= i)) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n - 1];
    }
};