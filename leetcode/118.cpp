class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ret(numRows, vector<int>());

        for (int i = 0; i < numRows; i++) {
            ret[i].push_back(1);
        }

        for (int i = 1; i < numRows; i++) {
            for (int j = 0; j < ret[i - 1].size() - 1; j++) {
                ret[i].push_back(ret[i - 1][j] + ret[i - 1][j + 1]);
            }
            ret[i].push_back(1);
        }

        return ret;
    }
};