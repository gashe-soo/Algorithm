class Solution {
public:
    int sumOfUnique(vector<int>& nums)
    {
        int maxlen = 101;

        vector<int> v(maxlen, 0);

        for (int i = 0; i < nums.size(); i++) {
            v[nums[i]]++;
        }

        int ans = 0;

        for (int i = 1; i < maxlen; i++) {
            if (v[i] == 1)
                ans += i;
        }
        return ans;
    }
};