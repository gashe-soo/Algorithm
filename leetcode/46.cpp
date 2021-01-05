class Solution {
public:
    void go(vector<vector<int>>& ans, int num, vector<int>& nums, vector<int>& ret, vector<bool>& v)
    {
        if (nums.size() == num) {
            ans.push_back(ret);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!v[i]) {
                v[i] = true;
                ret.push_back(nums[i]);
                go(ans, num + 1, nums, ret, v);
                ret.pop_back();
                v[i] = false;
            }
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<bool> v(nums.size(), 0);
        vector<int> ret;
        go(ans, 0, nums, ret, v);

        return ans;
    }
};