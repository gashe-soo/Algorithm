class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int low = INT_MAX;
        int ret = 0;

        for (int i = 0; i < prices.size(); i++) {
            low = min(low, prices[i]);
            ret = max(ret, prices[i] - low);
        }
        return ret;
    }
};