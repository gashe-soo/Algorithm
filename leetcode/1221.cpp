class Solution {
public:
    int balancedStringSplit(string s)
    {
        int ans = 0;
        int sum = 0;

        for (char c : s) {
            if (c == 'R') {
                sum++;
            } else {
                sum--;
            }
            if (sum == 0)
                ans++;
        }
        return ans;
    }
};