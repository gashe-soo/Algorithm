class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];

        vector<vector<int>> ret;

        for (int i = 1; i < intervals.size(); i++) {
            if (end < intervals[i][0]) {
                ret.push_back({ start, end });
                start = intervals[i][0];
                end = intervals[i][1];
            } else if (end < intervals[i][1]) {
                end = intervals[i][1];
            }
        }

        ret.push_back({ start, end });
        return ret;
    }
};