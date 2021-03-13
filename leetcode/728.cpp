class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            int num = i;
            while (num > 0) {
                int x = num % 10;
                if (x == 0 || i % x != 0) {
                    break;
                }
                num /= 10;
            }
            if (num == 0)
                ans.push_back(i);
        }
        return ans;
    }
};