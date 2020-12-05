class Solution {
public:
    struct Node {
        int x, y, d;
    };

    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> ret;

        int m = matrix.size();
        int n = matrix[0].size();

        if (m == 0)
            return ret;
        vector<vector<bool>> v(m, vector<bool>(n));

        int dx[4] = { 0, 1, 0, -1 };
        int dy[4] = { 1, 0, -1, 0 };

        queue<Node> q;

        q.push({ 0, 0, 0 });
        v[0][0] = 1;

        while (!q.empty()) {
            Node now = q.front();
            q.pop();

            int x = now.x, y = now.y, d = now.d;

            ret.push_back(matrix[x][y]);

            int nx = x + dx[d], ny = y + dy[d];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || v[nx][ny]) {
                d = (d + 1) % 4;
                nx = x + dx[d], ny = y + dy[d];
            }

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || v[nx][ny])
                continue;

            q.push({ nx, ny, d });
            v[nx][ny] = 1;
        }
        return ret;
    }
};