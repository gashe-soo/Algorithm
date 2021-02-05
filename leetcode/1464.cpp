class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        int ans = nums.back();
        nums.pop_back();

        return (ans - 1) * (nums.back() - 1);
    }
};