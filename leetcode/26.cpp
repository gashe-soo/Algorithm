class Solution {
public:
    // int removeDuplicates(vector<int>& nums) {
    //     nums.erase(unique(nums.begin(),nums.end()),nums.end());
    //     return nums.size();
    // }
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.size() == 0)
            return 0;

        int idx = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[idx]) {
                idx++;
                nums[idx] = nums[i];
            }
        }
        return idx + 1;
    }
};