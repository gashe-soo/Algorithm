class Solution {
public:
    int cnt = 0;
    int m, n;
    bool v[301][301];

    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };

    void bfs(vector<vector<char>>& grid, int x, int y)
    {
        if (v[x][y]) {
            return;
        }
        ++cnt;
        queue<pair<int, int>> q;

        v[x][y] = true;
        q.push({ x, y });

        while (!q.empty()) {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = a + dx[i], ny = b + dy[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || v[nx][ny] || grid[nx][ny] == '0')
                    continue;
                q.push({ nx, ny });
                v[nx][ny] = true;
            }
        }
    }

    int numIslands(vector<vector<char>>& grid)
    {
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                }
            }
        }

        return cnt;
    }
};