class Solution {
public:
    // linear search
    //     vector<int> searchRange(vector<int>& nums, int target) {
    //         int s = -1, e = -1;

    //         for(int i=0;i<nums.size();i++){
    //             if(nums[i]>target)
    //                 break;
    //             if(nums[i]==target){
    //                 e = i;
    //                 if(s==-1)
    //                     s = i;
    //             }
    //         }
    //         return {s,e};
    //     }
    // binary search
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int start = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

        if (start == nums.size() || nums[start] != target) {
            start = -1, end = -1;
        }

        return { start, end };
    }
};