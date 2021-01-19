class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> st(n, 1);
        vector<int> rev(n, 1);

        for (int i = 1; i < n; i++) {
            st[i] = st[i - 1] * nums[i - 1];
        }
        for (int i = n - 1; i >= 1; i--) {
            rev[i - 1] = rev[i] * nums[i];
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            ans.push_back(st[i] * rev[i]);
        }

        return ans;
    }
};