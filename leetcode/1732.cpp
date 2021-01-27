class Solution {
public:
    int largestAltitude(vector<int>& gain)
    {
        int h = 0;
        int ans = 0;
        for (const auto& i : gain) {
            h += i;
            if (h > ans) {
                ans = h;
            }
        }
        return ans;
    }
};