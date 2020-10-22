class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<int>& nums, vector<bool>& v, vector<int> arr, int idx)
    {
        ans.push_back(arr);

        for (int i = idx; i < nums.size(); i++) {
            if (!v[i]) {
                v[i] = true;

                arr.push_back(nums[i]);
                dfs(nums, v, arr, i);
                arr.pop_back();
                v[i] = false;
            }
        }
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<bool> v(nums.size(), false);
        dfs(nums, v, {}, 0);
        return ans;
    }
};